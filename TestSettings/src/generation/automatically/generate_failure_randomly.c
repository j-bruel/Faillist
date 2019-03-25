//!
//! @file generate_failure_randomly.c
//! @author jbruel
//! @date 11/02/19
//!

#include <stddef.h>
#include "generation/automatically/random_number_generator.h"
#include <time.h>
#include "report/faillure/id_component_failure/id_component_failure_def.h"
#include <memory.h>
#include <report/faillure/write_encoded_error_failure.h>
#include "report/faillure/failure_id/failure_id_def.h"
#include "generation/automatically/generate_failure_randomly.h"

bool    generate_failure_randomly(int fd, struct failure *failure)
{
    if (failure == NULL)
        return (false);

    int     id_plane_idx = GET_RANDOM_NB(0, FAILURE_ID_MAX - 1);
    int     id_component_idx = GET_RANDOM_NB(0, COMPONENT_ID_MAX - 1);

    failure->id_failure = id_failures[id_plane_idx].value;
    failure->date = (unsigned int)time(NULL);
    failure->id_component = id_components_failure[id_component_idx].value;
    failure->level_criticity = (unsigned int) (GET_RANDOM_NB(0, 10));
    failure->comment_failure_size = (unsigned int) strlen("Random error.");
    memset(failure->comment_failure, '\0', failure->comment_failure_size + 1);
    strncpy((char *) failure->comment_failure, "Random error.", failure->comment_failure_size);
    write_encoded_error_failure(1, failure);
    write_encoded_error_failure(fd, failure);
    return (true);
}