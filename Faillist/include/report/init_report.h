//!
//! @file init_report.h
//! @author jbruel
//! @date 11/02/19
//!

#ifndef FAILLIST_INIT_REPORT_H
# define FAILLIST_INIT_REPORT_H

# include "report/report.h"

//!
//! @brief Initialize report.
//! @note REQ_FUNC_010
//! @def void init_report(struct report *raised_error);
//! @param raised_error Raised errors.
//!
void init_report(struct report *raised_error);

#endif //FAILLIST_INIT_REPORT_H
