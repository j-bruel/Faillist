//!
//! @file write_type_plane.c
//! @author jbruel
//! @date 14/02/19
//!

#include "report/type_plane/type_planes_def.h"
#include <memory.h>
#include <unistd.h>

/**
 * Write type plane information into the log file.
 */
void    write_type_plane(int fd, unsigned int raised_type_plane)
{
    for (size_t i = 0; i < TYPE_PLANE_MAX; ++i)
        if (type_planes[i].value == raised_type_plane)
        {
            write(fd, type_planes[i].type_plane_desc, strlen(type_planes[i].type_plane_desc));
            write(fd, "\n", 1);
            return ;
        }
}