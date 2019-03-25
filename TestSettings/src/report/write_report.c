//!
//! @file write_report.c
//! @author jbruel
//! @date 14/02/19
//!

#include "report/write_report.h"
#include "report/type_plane/write_type_plane.h"
#include "report/id_plane/write_id_plane.h"
#include "report/faillure/write_failure.h"
#include <sys/stat.h>
#include <memory.h>
#include <unistd.h>
#include <stdio.h>

/**
 * Write all report information into the log file.
 */
void    write_report(int fd, struct report *report)
{
    struct stat st; // state file information.

    fstat(fd, &st);
    if (st.st_size == 0)
    {
        write(fd, FAILLURE_REPORT_HEADER_TXT, strlen(FAILLURE_REPORT_HEADER_TXT));
        write(fd, report->id_plane, strlen((const char *)report->id_plane));
        write(fd, "\n", 1);
        write_type_plane(fd, report->type_plane);
        write_id_plane(fd, &report->id_plane[0]);
    }
    for (size_t i = 0; i < report->nb_failures; ++i)
    {
        if (!write_failure(fd, i, &report->faillures[i])) {
            ;//dprintf(2, "Faillist: Warning, the %zu failure has been impossible to write on the output file.\n", i);
        }
    }
}