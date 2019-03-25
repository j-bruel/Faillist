//!
//! @file random_number_generator.h
//! @author jbruel
//! @date 11/02/19
//!

#ifndef T_800_EMB_FAILLIST_2018_RANDOM_NUMBER_GENERATOR_H
# define T_800_EMB_FAILLIST_2018_RANDOM_NUMBER_GENERATOR_H

# include <stdlib.h>

# define GET_RANDOM_NB(min, max)    (rand()%(max-min))+min

#endif //T_800_EMB_FAILLIST_2018_RANDOM_NUMBER_GENERATOR_H
