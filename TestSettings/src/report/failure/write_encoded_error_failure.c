//!
//! @file write_encoded_error_header.c
//! @author jbruel
//! @date 11/02/19
//!

#include <unistd.h>
#include <memory.h>
#include <stdio.h>
#include "report/faillure/write_encoded_error_failure.h"

void    write_encoded_error_failure(int fd, struct failure *failure)
{
    char id_failure[7];
    char current_date[11];
    char id_component[7];
    char level_criticity[3];
    char comment_size[5];

    memset(id_failure, '\0', 7);
    memset(current_date, '\0', 11);
    memset(id_component, '\0', 7);
    memset(level_criticity, '\0', 3);
    memset(comment_size, '\0', 5);
    sprintf(id_failure, "0x%x", failure->id_failure);
    sprintf(current_date, "%d", failure->date);
    sprintf(id_component, "0x%x", failure->id_component);
    sprintf(level_criticity, "%d", failure->level_criticity);
    sprintf(comment_size, "%d", failure->comment_failure_size > MAX_COMMENT_SIZE ? MAX_COMMENT_SIZE : failure->comment_failure_size);
    write(fd, "    {\n", strlen("    {\n"));
    write(fd, "      Id_failure: ", strlen("      Id_failure: "));
    write(fd, id_failure, strlen(id_failure));
    write(fd, ",\n", strlen(",\n"));
    write(fd, "      Date: ", strlen("      Date: "));
    write(fd, current_date, strlen(current_date));
    write(fd, ",\n", strlen(",\n"));
    write(fd, "      Id_component: ", strlen("      Id_component: "));
    write(fd, id_component, strlen(id_component));
    write(fd, ",\n", strlen(",\n"));
    write(fd, "      Level_criticity: ", strlen("      Level_criticity: "));
    write(fd, level_criticity, strlen(level_criticity));
    write(fd, ",\n", strlen(",\n"));
    write(fd, "      Comment_failure_size: ", strlen("      Comment_failure_size: "));
    write(fd, comment_size, strlen(comment_size));
    write(fd, ",\n", strlen(",\n"));
    write(fd, "      Comment_failure: \"", strlen("      Comment_failure: \""));
    write(fd, failure->comment_failure, strlen((const char *) failure->comment_failure));
    write(fd, "\"\n", strlen("\"\n"));
    write(fd, "    }", strlen("    }"));

}