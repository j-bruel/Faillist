//!
//! @file generate_report_randomly.h
//! @author jbruel
//! @date 11/02/19
//!

#ifndef T_800_EMB_FAILLIST_2018_GENERATE_REPORT_RANDOMLY_H
# define T_800_EMB_FAILLIST_2018_GENERATE_REPORT_RANDOMLY_H

# include "report/report.h"
# include <stdbool.h>

//!
//! @brief Generate a random report.
//! @def bool    generate_report_randomly(struct report *raised_error);
//! @note REQ_TEST_060
//! @param fd File director.
//! @param raised_error Report generate randomly.
//! @param nb_failure Number of failure.
//! @return State
//!
bool    generate_report_randomly(int fd, struct report *raised_error, int nb_failure);

#endif //T_800_EMB_FAILLIST_2018_GENERATE_REPORT_RANDOMLY_H
