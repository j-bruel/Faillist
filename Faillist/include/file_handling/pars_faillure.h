//!
//! @file pars_faillure.h
//! @author jbruel
//! @date 13/02/19
//!

#ifndef FAILLIST_PARS_FAILLURE_H
# define FAILLIST_PARS_FAILLURE_H

# include "report/faillure/failure.h"
# include <stdbool.h>
# include <stddef.h>

//!
//! @brief Faillure parser.
//! @def bool    pars_faillure(char *in, size_t in_size, struct failure *faillure);
//! @note REQ_FUNC_010
//! @param in Input data.
//! @param in_size Input data size.
//! @param faillure Faillure struct to load.
//! @return State.
//!
bool    pars_faillure(char *in, size_t in_size, struct failure *faillure);

#endif //FAILLIST_PARS_FAILLURE_H
