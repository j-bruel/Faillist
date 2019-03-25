//!
//! @file init_failure.c
//! @author jbruel
//! @date 11/02/19
//!

#include <memory.h>
#include "report/faillure/failure.h"

void    init_failure(struct failure *error)
{
    error->id_failure = 0;
    error->date = 0;
    error->id_component = 0;
    error->level_criticity = 0;
    error->comment_failure_size = 0;
    memset(error->comment_failure, '\0', MAX_COMMENT_SIZE);
}