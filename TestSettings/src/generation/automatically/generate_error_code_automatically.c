//!
//! @file generate_error_code_automatically.c
//! @author jbruel
//! @date 11/02/19
//!

#include "generation/automatically/generate_error_code_automatically.h"
#include "generation/automatically/generate_report_randomly.h"
#include "report/file_max_size.h"
#include "report/report.h"
#include "report/init_report.h"
#include "report/write_report.h"
#include <stddef.h>
#include <stdlib.h>
#include <memory.h>

/**
 * Generate error code automatically with a define failure number.
 */
bool    generate_error_code_automatically(int fd, struct report *raised_error, const char *nb_failure)
{
    int             i_nb_failure; // number failure integer type.
    char            error_code[FILE_MAX_SIZE]; // error code value.

    if (nb_failure == NULL)
        return (false);
    i_nb_failure = atoi(nb_failure);
    if (i_nb_failure > 999)
        i_nb_failure = 999;
    memset(error_code, '\0', FILE_MAX_SIZE);
    if (!generate_report_randomly(fd, raised_error, i_nb_failure))
        return (false);
    return (true);
}