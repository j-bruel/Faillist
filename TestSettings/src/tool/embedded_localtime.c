//!
//! @file embedded_localtime.c
//! @author agrosso
//! @date 11/02/19
//!

#include "tool/embedded_localtime.h"

/**
 * Custom function to replace c localtime.
 */
void    embedded_localtime(time_t *rawtime, struct tm *timeinfo)
{
    time_t  stime; // Tmp variable to know how much second available.

    if (!rawtime || !timeinfo)
        return;
    stime = *rawtime;
    timeinfo->tm_year = (int)(stime / (YEAR_DAY * DAY_SEC)) + 70;
    stime -= ((timeinfo->tm_year - 70) * 31536000
              + ((timeinfo->tm_year - 69) / 4) * DAY_SEC
              - ((timeinfo->tm_year - 1) / 100) * DAY_SEC
              + ((timeinfo->tm_year + 299) / 400) * DAY_SEC);
    timeinfo->tm_yday = (int)(stime / DAY_SEC);
    stime = stime % DAY_SEC;
    timeinfo->tm_mon = (int)(timeinfo->tm_yday / MONTH_DAY);
    timeinfo->tm_mday = (int)(timeinfo->tm_yday - (timeinfo->tm_mon * MONTH_DAY)) + 1;
    timeinfo->tm_hour = (int)(stime / HOUR_SEC) + 1;
    stime = stime % HOUR_SEC;
    timeinfo->tm_min = (int)(stime / MIN_SEC);
    stime = stime % MIN_SEC;
    timeinfo->tm_sec = (int)(stime);
}