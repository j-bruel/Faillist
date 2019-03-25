//!
//! @file write_encoded_error_header.h
//! @author jbruel
//! @date 11/02/19
//!

#ifndef T_800_EMB_FAILLIST_2018_WRITE_ENCODED_ERROR_HEADER_H
# define T_800_EMB_FAILLIST_2018_WRITE_ENCODED_ERROR_HEADER_H

# include "report/report.h"

//!
//! @brief Write encoded error header.
//! @def void write_encoded_error_header(int fd, struct report *raised_error);
//! @note REQ_TEST_030
//! @param fd File director.
//! @param raised_error Raised error containing all informations
//!
void write_encoded_error_header(int fd, struct report *raised_error);

#endif //T_800_EMB_FAILLIST_2018_WRITE_ENCODED_ERROR_HEADER_H
