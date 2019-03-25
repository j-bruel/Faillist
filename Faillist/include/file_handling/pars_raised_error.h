//!
//! @file pars_raised_error.h
//! @author jbruel
//! @date 11/02/19
//!

#ifndef FAILLIST_PARS_RAISED_ERROR_H
# define FAILLIST_PARS_RAISED_ERROR_H

# include "report/file_max_size.h"
# include "report/report.h"
# include <stdbool.h>
# include <stddef.h>

//!
//! @brief Pars raised error with json parser.
//! @def struct report   pars_raised_error(char in[FILE_MAX_SIZE]);
//! @note REQ_FUNC_010
//! @param in Input data.
//! @param in_size Input data size.
//! @param raised_error Raised errors.
//! @return State.
//!
bool    pars_raised_error(char *in, size_t in_size, struct report *raised_error);

#endif //FAILLIST_PARS_RAISED_ERROR_H
