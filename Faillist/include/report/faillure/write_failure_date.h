//!
//! @file write_failure_date.h
//! @author jbruel
//! @date 20/02/19
//!

#ifndef FAILLIST_WRITE_FAILURE_DATE_H
# define FAILLIST_WRITE_FAILURE_DATE_H

# include <stdbool.h>

//!
//! @def FAILURE_DATE_TXT_MAX_SIZE
//! @brief Failure date txt max size.
//!
# define FAILURE_DATE_TXT_MAX_SIZE  30

//!
//! @brief Write failure date.
//! @def bool    write_failure_date(int fd, unsigned int date);
//! @note REQ_FUNC_120
//! @param fd File director.
//! @param date Date.
//! @return State.
//!
bool    write_failure_date(int fd, unsigned int date);

#endif //FAILLIST_WRITE_FAILURE_DATE_H
