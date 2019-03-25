//!
//! @file write_encoded_error_header.c
//! @author jbruel
//! @date 11/02/19
//!

#include "report/write_encoded_error_failure.h"
#include <unistd.h>
#include <memory.h>
#include <stdio.h>

/**
 * Write encoded error header.
 */
void    write_encoded_error_header(int fd, struct report *raised_error)
{
    char type_plane[7];
    char nb_failure[4];

    memset(type_plane, '\0', 7);
    memset(nb_failure, '\0', 4);
    write(fd, "{\n  Id_plane: \"", strlen("{\n  Id_plane: \""));
    write(fd, raised_error->id_plane, strlen((const char *)raised_error->id_plane));
    write(fd, "\",\n", strlen("\",\n"));
    write(fd, "  Type_plane: ", strlen("  Type_plane: "));
    sprintf(type_plane, "0x%x", raised_error->type_plane);
    write(fd, type_plane, strlen(type_plane));
    write(fd, ",\n", strlen(",\n"));
    write(fd, "  Nb_failures: ", strlen("  Nb_failures: "));
    sprintf(nb_failure, "%d", raised_error->nb_failures);
    write(fd, nb_failure, strlen(nb_failure));
    write(fd, ",\n", strlen(",\n"));
    write(fd, "  failures: [\n", strlen("  failures: [\n"));
}