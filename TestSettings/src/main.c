//!
//! @file main.c
//! @author jbruel
//! @date 11/02/19
//!

#include "generation/witch_error_generation_type_is.h"
#include "generation/automatically/generate_error_code_automatically.h"
#include "report/report.h"
#include "report/init_report.h"
#include "report/write_report.h"
#include "conf/show_help.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <memory.h>
#include <file_handling/open_encoded_error_file.h>
#include <file_handling/close_encoded_error_file.h>
#include <generation/exec_faillist_app.h>
#include <stdio.h>
#include <generation/manually/generate_error_code_manually.h>

/**
 * Main function.
 */
int     main(int argc, const char *argv[])
{
    int                         generation_arg_idx = 0; // User input arguments index for generation argument information.
    int                         faillist_app_path_arg_idx = 0; // User input arguments index for generation argument information.
    enum error_generation_type  type = witch_error_generation_type_is(argc, argv, &generation_arg_idx, &faillist_app_path_arg_idx); // Error generation type asked by the user.
    int                         fd = -1; // output file file director.
    struct report               raised_error; // Raised error.
    char                        file_path[24]; // output file path use for faillist application (.TestSettings/X.json)

    srand(time(NULL));
    init_report(&raised_error);
    memset(file_path, '\0', 24);
    if (type == NONE)
    {
        show_help(argc, argv);
        return (EXIT_FAILURE);
    }
    fd = open_encoded_error_file(file_path);
    if (fd == -1)
    {
        write(1, "ERROR! Impossible to create the output file for faillsit application.\n", strlen("ERROR! Impossible to create the output file for faillsit application.\n"));
        return (EXIT_FAILURE);
    }
    if (type == MANUALLY)
        generate_error_code_manually(fd, &raised_error, argv[generation_arg_idx]);
    else if (type == AUTOMATICALLY)
        generate_error_code_automatically(fd, &raised_error, argv[generation_arg_idx]);
    exec_faillist_app(argv[faillist_app_path_arg_idx], file_path);
    close_encoded_error_file(fd, file_path);
    return (EXIT_SUCCESS);
}