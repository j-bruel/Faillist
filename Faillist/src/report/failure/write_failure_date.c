//!
//! @file write_failure_date.c
//! @author jbruel
//! @date 20/02/19
//!

#include "report/faillure/write_failure_date.h"
#include "tool/embedded_localtime.h"
#include <memory.h>
#include <unistd.h>

/**
 * Write failure date.
 */
bool    write_failure_date(int fd, unsigned int date)
{
    char        failure_date[FAILURE_DATE_TXT_MAX_SIZE]; // failure date text output.
    time_t      t = date; // date into time_t format.
    struct tm   time_info; // Time informations.

    memset(failure_date, '\0', FAILURE_DATE_TXT_MAX_SIZE);
    embedded_localtime(&t, &time_info);
    if (strftime(failure_date, FAILURE_DATE_TXT_MAX_SIZE, "TIME: %Y/%m/%d - %H:%M:%S\n", &time_info) <= 0)
        return (false);
    write(fd, failure_date, strlen(failure_date));
    return (true);
}