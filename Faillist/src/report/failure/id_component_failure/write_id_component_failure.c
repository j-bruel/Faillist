//!
//! @file write_id_component_failure.c
//! @author jbruel
//! @date 20/02/19
//!

#include <unistd.h>
#include <report/faillure/id_component_failure/id_component_failure_def.h>
#include <memory.h>
#include <stdio.h>
#include "report/faillure/id_component_failure/write_id_component_failure.h"

/**
 * Write id component failure.
 */
bool    write_id_component_failure(int fd, unsigned int id_component)
{
    char    t_id_component_failure[ID_COMPONENT_FAILURE_TEXT_MAX_SIZE]; // ID Component failure output.

    if (fd < 0 ||
        id_component > 9999)
        return (false);
    for (size_t i = 0; i < COMPONENT_ID_MAX; ++i)
        if (id_components_failure[i].value == id_component)
        {
            memset(t_id_component_failure, '\0', ID_COMPONENT_FAILURE_TEXT_MAX_SIZE);
            sprintf(t_id_component_failure, "COMPONENT FAILURE: %s\n", id_components_failure[i].component_desc);
            write(fd, t_id_component_failure, strlen(t_id_component_failure));
            return (true);
        }
    return (false);
}