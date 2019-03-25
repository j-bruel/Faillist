//!
//! @file init_report.c
//! @author jbruel
//! @date 11/02/19
//!

#include "report/init_report.h"
#include "report/faillure/failure_info_max_allow.h"
#include <memory.h>
#include <stddef.h>

/**
 * Initialize report.
 */
void init_report(struct report *raised_error)
{
    if (raised_error == NULL)
        return ;
    memset(raised_error->id_plane, '\0', ID_PLANE_MAX_SIZE);
    raised_error->type_plane = 0;
    raised_error->nb_failures = 0;
    for (size_t i = 0; i < FAILURE_INFO_MAX_ALLOW; ++i)
    {
        raised_error->faillures[i].id_failure = 0;
        raised_error->faillures[i].date = 0;
        raised_error->faillures[i].id_component = 0;
        raised_error->faillures[i].level_criticity = 0;
        raised_error->faillures[i].comment_failure_size = 0;
        memset(raised_error->faillures[i].comment_failure, '\0', MAX_COMMENT_SIZE);
    }
}