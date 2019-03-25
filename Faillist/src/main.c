//!
//! @file main.c
//! @author jbruel
//! @date 11/02/19
//!

#include "file_handling/file_reader.h"
#include "file_handling/pars_raised_error.h"
#include "report/init_report.h"
#include "report/open_report.h"
#include "report/write_report.h"
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <unistd.h>

/**
 * Main function.
 */
int     main(int argc, const char *argv[])
{
    char            in[FILE_MAX_SIZE]; // Input file content.
    struct report   raised_error; // Report (raised error catched).
    int             out_fd; // out file director (log output file).

    if (argc != 2)
    {
        write(1, "Usage: ", strlen("Usage: "));
        write(1, argv[0], strlen(argv[0]));
        write(1, " [RAISED_ERROR_FILEPATH]\n", strlen(" [RAISED_ERROR_FILEPATH]\n"));
        return (EXIT_FAILURE);
    }
    init_report(&raised_error);
    if (!file_reader(argv[1], &(in[0])))
        return (EXIT_FAILURE);
    if (!pars_raised_error(in, strlen(in), &raised_error))
        return (EXIT_FAILURE);
    if ((out_fd = open_report(&raised_error)) == -1)
    {
        write(1, "Faillist: Impossible to create the output file.", strlen("Faillist: Impossible to create the output file."));
        return (EXIT_FAILURE);
    }
    write_report(out_fd, &raised_error);
    close(out_fd);
    write(1, "Faillist: Logging finish with success.\n", strlen("Faillist: Logging finish with success.\n"));
    return (EXIT_SUCCESS);
}