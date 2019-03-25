//!
//! @file generate_report_randomly.c
//! @author jbruel
//! @date 11/02/19
//!

#include "generation/automatically/generate_report_randomly.h"
#include "generation/automatically/generate_failure_randomly.h"
#include "generation/automatically/random_number_generator.h"
#include "report/id_plane/id_plane_def.h"
#include "report/type_plane/type_planes_def.h"
#include <stddef.h>
#include <memory.h>
#include <stdio.h>
#include <unistd.h>
#include <report/write_encoded_error_failure.h>
#include <report/faillure/init_failure.h>

bool    generate_report_randomly(int fd, struct report *raised_error, int nb_failure)
{
    if (raised_error == NULL || nb_failure <= 0)
        return (false);

    int             id_plane_idx = GET_RANDOM_NB(0, MAX_ID_PLANE - 1);
    int             type_plane_idx = GET_RANDOM_NB(0, TYPE_PLANE_MAX - 1);
    struct failure  error_failure;

    strncpy((char *) raised_error->id_plane, (const char *) id_planes[id_plane_idx].prefix,
            strlen((const char *) id_planes[id_plane_idx].prefix) > ID_PLANE_MAX_SIZE ? ID_PLANE_MAX_SIZE : strlen((const char *) id_planes[id_plane_idx].prefix));
    raised_error->type_plane = type_planes[type_plane_idx].value;
    raised_error->nb_failures = (unsigned int)nb_failure;
    write_encoded_error_header(1, raised_error);
    write_encoded_error_header(fd, raised_error);
    for (unsigned int i = 0; i < raised_error->nb_failures; ++i)
    {
        init_failure(&error_failure);
        if (!generate_failure_randomly(fd, &error_failure))
            return (false);
        if (i + 1 < raised_error->nb_failures)
        {
            write(1, ",", 1);
            write(fd, ",", 1);
        }
        write(1, "\n", 1);
        write(fd, "\n", 1);
    }
    write(1, "  ]\n}\n", strlen("  ]\n}\n"));
    write(fd, "  ]\n}\n", strlen("  ]\n}\n"));
    return (true);
}