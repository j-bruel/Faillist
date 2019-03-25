//!
//! @file open_report.h
//! @author jbruel
//! @date 14/02/19
//!

#ifndef FAILLIST_OPEN_REPORT_H
# define FAILLIST_OPEN_REPORT_H

# include "report/report.h"

//!
//! @def EXTRACTION_REPORT_NAME_MAX_SIZE
//! @brief Extraction report name max size.
//!
# define EXTRACTION_REPORT_NAME_MAX_SIZE    57

//!
//! @def REPORT_DATE_TEXT_MAX_SIZE
//! @brief Report date text max size.
//!
# define REPORT_DATE_TEXT_MAX_SIZE      20

//!
//! @brief Open report file.
//! @def int open_report(struct report *raised_error);
//! @note REQ_FUNC_180
//! @param raised_error Raised error struct information.
//! @return File director.
//!
int open_report(struct report *raised_error);

#endif //FAILLIST_OPEN_REPORT_H
