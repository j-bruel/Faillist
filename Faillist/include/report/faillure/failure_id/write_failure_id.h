//!
//! @file write_failure_id.h
//! @author jbruel
//! @date 20/02/19
//!

#ifndef FAILLIST_WRITE_FAILURE_ID_H
# define FAILLIST_WRITE_FAILURE_ID_H

# include <stddef.h>
# include <stdbool.h>

//!
//! @def FAILURE_NB_TEXT_MAX_SIZE
//! @brief Failure Id log text max size.
//!
# define FAILURE_NB_TEXT_MAX_SIZE   50

//!
//! @brief Write failure id on log file.
//! @def bool    write_failure_id(int fd, size_t idx, unsigned int failure_id);
//! @note REQ_FUNC_120
//! @param fd File director.
//! @param idx Failure idx.
//! @param failure_id Failure id.
//! @return State.
//!
bool    write_failure_id(int fd, size_t idx, unsigned int failure_id);

#endif //FAILLIST_WRITE_FAILURE_ID_H
