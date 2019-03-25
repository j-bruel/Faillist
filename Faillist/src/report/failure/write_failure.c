//!
//! @file write_failure.cpp
//! @author jbruel
//! @date 20/02/19
//!

#include "report/faillure/write_failure_date.h"
#include "report/faillure/id_component_failure/write_id_component_failure.h"
#include "report/faillure/failure_id/write_failure_id.h"
#include "report/faillure/write_failure.h"
#include "report/faillure/failure_info_max_allow.h"
#include <stdio.h>
#include <memory.h>
#include <unistd.h>

/**
 * Write into the file a faillure information.
 */
bool    write_failure(int fd, size_t idx, struct failure *failure)
{
    char t_level_criticity[22]; // Level criticity text.

    if (failure == NULL ||
        idx > FAILURE_INFO_MAX_ALLOW)
        return (false);
    if (idx > 0)
        write(fd, "----------\n", 11);
    if (!write_failure_id(fd, idx, failure->id_failure) ||
        !write_failure_date(fd, failure->date) ||
        !write_id_component_failure(fd, failure->id_component))
        return (false);
    if (failure->level_criticity > 10)
        return (false);
    memset(t_level_criticity, '\0', 22);
    sprintf(t_level_criticity, "LEVEL CRITICITY: %d\n", failure->level_criticity);
    write(fd, t_level_criticity, strlen(t_level_criticity));
    if (failure->comment_failure_size == 0)
        return (false);
    write(fd, "COMMENT: ", 9);
    if (failure->comment_failure_size > FAILURE_INFO_MAX_ALLOW)
        write(fd, failure->comment_failure, strlen((const char *) failure->comment_failure) > FAILURE_INFO_MAX_ALLOW ? FAILURE_INFO_MAX_ALLOW : strlen(
                (const char *) failure->comment_failure));
    else
        write(fd, failure->comment_failure, strlen((const char *) failure->comment_failure) > failure->comment_failure_size ? failure->comment_failure_size : strlen(
                (const char *) failure->comment_failure));
    write(fd, "\n", 1);
    return (true);
}
