//!
//! @file generate_failure_randomly.h
//! @author jbruel
//! @date 11/02/19
//!

#ifndef T_800_EMB_FAILLIST_2018_GENERATE_FAILURE_RANDOMLY_H
# define T_800_EMB_FAILLIST_2018_GENERATE_FAILURE_RANDOMLY_H

# include <stdbool.h>
# include "report/faillure/failure.h"

bool    generate_failure_randomly(int fd, struct failure *failure);

#endif //T_800_EMB_FAILLIST_2018_GENERATE_FAILURE_RANDOMLY_H
