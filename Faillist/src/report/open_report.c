//!
//! @file open_reaport.c
//! @author jbruel
//! @date 14/02/19
//!

#include "report/open_report.h"
#include "tool/embedded_localtime.h"
#include <memory.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>

/**
 * Open report file.
 */
int    open_report(struct report *raised_error)
{
    char        report[EXTRACTION_REPORT_NAME_MAX_SIZE]; // report file name.
    char        report_date[REPORT_DATE_TEXT_MAX_SIZE]; // report date.
    time_t      current_time = time(NULL); // current time.
    struct tm   time_info; // Time informations.

    if (raised_error == NULL)
        return (-1);
    memset(report_date, '\0', REPORT_DATE_TEXT_MAX_SIZE);
    embedded_localtime(&current_time, &time_info);
    if (strftime(report_date, REPORT_DATE_TEXT_MAX_SIZE, "%Y_%m_%d_%H_%M_%S", &time_info) <= 0)
        return (-1);
    memset(report, '\0', EXTRACTION_REPORT_NAME_MAX_SIZE);
    sprintf(report, "./Extraction_report_%s_%s.txt", raised_error->id_plane, report_date);
    write(1, "Faillist: Creating the output file: ", strlen("Faillist: Creating the output file: "));
    write(1, report, strlen(report));
    write(1, ".\n", 2);
    return (open(report, O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}