//!
//! @file write_report.h
//! @author jbruel
//! @date 14/02/19
//!

#ifndef TESTSETTINGS_WRITE_REPORT_H
# define TESTSETTINGS_WRITE_REPORT_H

# include "report/report.h"

//!
//! @def FAILLURE_REPORT_HEADER_TXT
//! @brief Failure header text.
//!
# define FAILLURE_REPORT_HEADER_TXT "FAILURE REPORT\n\n"

//!
//! @brief Write all report information into the log file.
//! @def void write_report(int fd, struct report *report);
//! @note REQ_FUNC_120
//! @param fd File director of the report file.
//! @param report Report structure information.
//!
void write_report(int fd, struct report *report);

#endif //TESTSETTINGS_WRITE_REPORT_H
