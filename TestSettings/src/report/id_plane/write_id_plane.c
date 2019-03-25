//!
//! @file write_id_plane.c
//! @author jbruel
//! @date 16/02/19
//!

#include "report/id_plane/write_id_plane.h"
#include "report/id_plane/id_plane_def.h"
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>

/**
 * Write id plane.
 */
void    write_id_plane(int fd, unsigned char *raised_id_plane)
{
    for (size_t i = 0; i < MAX_ID_PLANE; ++i)
        if (strncmp((const char *) id_planes[i].prefix, (const char *) raised_id_plane, ID_PLANE_MAX_SIZE) == 0)
        {
            write(fd, PLANE_NATIONALITY_TEXT, strlen(PLANE_NATIONALITY_TEXT));
            write(fd, id_planes[i].country, strlen((const char *)id_planes[i].country));
            write(fd, "\n----------\n", 12);
            return ;
        }
}