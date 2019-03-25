//!
//! @file generate_error_code_automatically.h
//! @author jbruel
//! @date 11/02/19
//!

#ifndef T_800_EMB_FAILLIST_2018_GENERATE_ERROR_CODE_AUTOMATICALLY_H
# define T_800_EMB_FAILLIST_2018_GENERATE_ERROR_CODE_AUTOMATICALLY_H

# include "report/report.h"
# include <stdbool.h>

//!
//! @brief Generate error code automatically with a define failure number.
//! @def bool    generate_error_code_automatically(const char *nb_failure);
//! @note REQ_TEST_060
//! @param fd File director.
//! @param raised_error Raised error, use as output.
//! @param nb_failure Failure number to generate.
//! @return State.
//!
bool    generate_error_code_automatically(int fd, struct report *raised_error, const char *nb_failure);

#endif //T_800_EMB_FAILLIST_2018_GENERATE_ERROR_CODE_AUTOMATICALLY_H
