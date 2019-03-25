//!
//! @file write_faillure.h
//! @author jbruel
//! @date 20/02/19
//!

#ifndef FAILLIST_WRITE_FAILLURE_H
# define FAILLIST_WRITE_FAILLURE_H

# include "report/faillure/failure.h"
# include <stdlib.h>
# include <stdbool.h>

//!
//! @brief Write into the file a faillure information.
//! @def void    write_failure(int fd, size_t idx, struct failure *failure);
//! @note REQ_FUNC_120
//! @param fd File directory.
//! @param idx Failure index.
//! @param failure Failure informations
//! @return State.
//!
bool    write_failure(int fd, size_t idx, struct failure *failure);

#endif //FAILLIST_WRITE_FAILLURE_H
