//!
//! @file generate_error_code_manually.c
//! @author jbruel
//! @date 17/02/19
//!

#include "report/write_encoded_error_failure.h"
#include "file_handling/pars_raised_error.h"
#include "file_handling/file_reader.h"
#include "report/file_max_size.h"
#include "generation/manually/generate_error_code_manually.h"
#include <unistd.h>
#include <memory.h>
#include <report/faillure/write_encoded_error_failure.h>

bool    generate_error_code_manually(int fd, struct report *raised_error, const char *file_path)
{
    char    file_content[FILE_MAX_SIZE]; // File content

    if (raised_error == NULL ||
        file_path == NULL)
        return (false);
    if (!file_reader(file_path, &(file_content[0])) ||
        !pars_raised_error(&(file_content[0]), strlen(file_content), raised_error))
        return (false);
    if (raised_error->nb_failures > 3)
        raised_error->nb_failures = 3;
    write_encoded_error_header(1, raised_error);
    write_encoded_error_header(fd, raised_error);
    for (unsigned int i = 0; i < raised_error->nb_failures; ++i)
    {
        write_encoded_error_failure(1, &raised_error->faillures[i]);
        write_encoded_error_failure(fd, &raised_error->faillures[i]);
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