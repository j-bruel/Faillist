//!
//! @file test_write_failure_date.c
//! @author jbruel
//! @date 20/02/19
//!

#include <np.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <time.h>
#include "report/faillure/write_failure_date.h"
#include "test_write_failure_date.h"

size_t  mock_strftime_return_zero(__attribute__((unused)) char *__restrict __s,
                                  __attribute__((unused)) size_t __maxsize,
                                  __attribute__((unused)) const char *__restrict __format,
                                  __attribute__((unused)) const struct tm *__restrict __tp)
{
    return (0);
}

// ------------------------- STARTING TESTS -------------------------

static void test_write_failure_BR1_CS1( void )
{
    // Test case 1 : INS_007 with inflexion value NULL.

    // Parameters
    int             fd = 1; // File directory.
    unsigned int    date = 0; // Date
    bool            ret = false; // Return status

    printf( "**** Run test case 1 on branch 1 => Check INS_003 with inflexion value NULL.\n");

    // -----
    // Mocks
    // Link mock mock_strftime_return_zero with 0 value for INS_007
    np_mock(strftime, mock_strftime_return_zero);

    // -----
    // Run function
    ret = write_failure_date(fd, date);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_write_failure_BR2_CS2( void )
{
    // Test case 1 : Full branch 2 test.

    // Parameters
    int             fd = 1; // File directory.
    unsigned int    date = time(NULL); // Date
    bool            ret = false; // Return status

    printf( "**** Run test case 2 on branch 2 => Check full branch 2.\n");

    // -----
    // Run function
    ret = write_failure_date(fd, date);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}