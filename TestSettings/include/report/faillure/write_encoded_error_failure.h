//!
//! @file write_encoded_error_failure.h
//! @author jbruel
//! @date 11/02/19
//!

#ifndef T_800_EMB_FAILLIST_2018_WRITE_ENCODED_ERROR_FAILURE_H
# define T_800_EMB_FAILLIST_2018_WRITE_ENCODED_ERROR_FAILURE_H

# include "report/faillure/failure.h"

//!
//! @brief Write on specific out all failure information in encoded format.
//! @note REQ_TEST_030
//! @def void write_encoded_error_header(int fd, struct failure *failure);
//! @param fd File director.
//! @param failure Failure information.
//!
void write_encoded_error_failure(int fd, struct failure *failure);

#endif //T_800_EMB_FAILLIST_2018_WRITE_ENCODED_ERROR_FAILURE_H
