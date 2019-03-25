//!
//! @file write_failure_id.c
//! @author jbruel
//! @date 20/02/19
//!

#include <memory.h>
#include <stdio.h>
#include <unistd.h>
#include <report/faillure/failure_id/failure_id_def.h>
#include <report/faillure/failure_id/failure_id.h>
#include "report/faillure/failure_id/write_failure_id.h"

/**
 * Write failure id on log file.
 */
bool    write_failure_id(int fd, size_t idx, unsigned int failure_id)
{
    char    t_failure_id[FAILURE_NB_TEXT_MAX_SIZE]; // Failure id output.

    if (failure_id > 9999)
        return (false);
    for (size_t i = 0; i < FAILURE_ID_MAX; ++i)
        if (id_failures[i].value == failure_id)
        {
            memset(t_failure_id, '\0', FAILURE_NB_TEXT_MAX_SIZE);
            sprintf(t_failure_id, "FAILURE %zu: %s\n", idx, id_failures[i].failure_type);
            write(fd, t_failure_id, strlen(t_failure_id));
            return (true);
        }
    return (false);
}