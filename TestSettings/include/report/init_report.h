//!
//! @file init_report.h
//! @author jbruel
//! @date 11/02/19
//!

#ifndef TESTSETTINGS_INIT_REPORT_H
# define TESTSETTINGS_INIT_REPORT_H

# include "report/report.h"

//!
//! @brief Initialize report.
//! @note REQ_FUNC_010
//! @def void init_report(struct report *raised_error);
//! @param raised_error Raised errors.
//!
void init_report(struct report *raised_error);

#endif //TESTSETTINGS_INIT_REPORT_H
