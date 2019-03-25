//!
//! @file embedded_localtime.h
//! @author jbruel
//! @date 11/02/19
//!

#ifndef FAILLIST_TOOL_EMBEDDED_LOCALTIME_H
# define FAILLIST_TOOL_EMBEDDED_LOCALTIME_H

#include <time.h>

//!
//!@brief Number of seconds in a minute.
//!@def MIN_SEC(60)
//!
# define MIN_SEC 60

//!
//!@brief Number of seconds in a hour.
//!@def HOUR_SEC(3600)
//!
# define HOUR_SEC 3600

//!
//!@brief Number of seconds in a day.
//!@def DAY_SEC(86400)
//!
# define DAY_SEC 86400

//!
//!@brief Number of days in a month.
//!@def MONTH_DAY(30.44)
//!
# define MONTH_DAY 30.44

//!
//! @brief Number of days in a year with loop year included.
//! @def YEAR_DAY(365.2425)
//!
# define YEAR_DAY 365.2425

//!
//! @brief Custom function to replace c localtime.
//! @def void embedded_localtime(time_t *rawtime, struct tm *timeinfo)
//! @note NONE
//! @param rawtime Unix epoch time used to compute timeinfo
//! @param timeinfo Struct to fill
//!
void    embedded_localtime(time_t *rawtime, struct tm *timeinfo);

#endif //FAILLIST_TOOL_EMBEDDED_LOCALTIME_H
