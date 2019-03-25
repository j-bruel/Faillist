//!
//! @file generate_error_code_manually.h
//! @author jbruel
//! @date 17/02/19
//!

#ifndef T_800_EMB_FAILLIST_2018_GENERATE_ERROR_CODE_MANUALLY_H
# define T_800_EMB_FAILLIST_2018_GENERATE_ERROR_CODE_MANUALLY_H

# include "report/report.h"
# include <stdbool.h>

//!
//! @brief Generate error code automatically with a define failure number.
//! @def bool    generate_error_code_manually(int fd, struct report *raised_error, const char *nb_failure);
//! @note REQ_TEST_050
//! @param fd File director.
//! @param raised_error Raised error, use as output.
//! @param file_path Failure path.
//! @return State.
//!
bool    generate_error_code_manually(int fd, struct report *raised_error, const char *file_path);


#endif //T_800_EMB_FAILLIST_2018_GENERATE_ERROR_CODE_MANUALLY_H
