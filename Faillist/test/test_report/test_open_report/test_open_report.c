//!
//! @file test_open_report.c
//! @author jbruel
//! @date 04/03/19
//!

#include <np.h>
#include <memory.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include "report/open_report.h"
#include "report/init_report.h"
#include "test_open_report.h"

size_t  mock_strftime_zero(__attribute__((unused)) char *__restrict __s,
                           __attribute__((unused)) size_t __maxsize,
                           __attribute__((unused)) const char *__restrict __format,
                           __attribute__((unused)) const struct tm *__restrict __tp)
{
    return (0);
}

// ------------------------- STARTING TESTS -------------------------

static void test_open_report_BR1_CS1( void )
{
    // Test case 1 : INS_005 with inflexion value NULL.

    // Parameters
    struct report   *raised_error = NULL; // Raised errors.

    printf( "**** Run test case 1 on branch 1 => Check INS_005 with inflexion value NULL.\n");

    // -----
    // Run function
    open_report(raised_error);
}

static void test_open_report_BR2_CS2( void )
{
    // Test case 2 : INS_010 with inflexion value 0.

    // Parameters
    struct report   raised_error; // Raised errors.

    printf( "**** Run test case 2 on branch 2 => Check INS_010 with inflexion value 0.\n");

    // -----
    // Mocks
    // Link mock mock_strftime_zero with 0 value for INS_010
    np_mock(strftime, mock_strftime_zero);

    init_report(&raised_error);
    // -----
    // Run function
    open_report(&raised_error);
}

static void test_open_report_BR3_BR4_CS3( void )
{
    // Test case 3 : INS_010 with inflexion value 0.

    // Parameters
    struct report   raised_error; // Raised errors.

    printf( "**** Run test case 3 on branch 3 & 4 => Check full branch.\n");

    init_report(&raised_error);
    // -----
    // Run function
    int fd = open_report(&raised_error);

    close(fd);
}