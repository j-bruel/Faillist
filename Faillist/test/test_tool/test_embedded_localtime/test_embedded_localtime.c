//!
//! @file test_embedded_localtime.c
//! @author jbruel
//! @date 04/03/19
//!

#include <np.h>
#include <stdio.h>
#include "tool/embedded_localtime.h"
#include "test_embedded_localtime.h"

// ------------------------- STARTING TESTS -------------------------

static void test_embedded_localtime_BR1_CS1( void )
{
    // Test case 1 : INS_003 with inflexion value NULL.

    // Parameters
    time_t      *rawtime = NULL;
    struct tm   timeinfo;

    printf( "**** Run test case 1 on branch 1 => Check INS_003 with inflexion value NULL.\n");

    // -----
    // Run function
    embedded_localtime(rawtime, &timeinfo);
}

static void test_embedded_localtime_BR2_CS2( void )
{
    // Test case 2 : INS_004 with inflexion value NULL.

    // Parameters
    time_t      rawtime = time(NULL);
    struct tm   *timeinfo = NULL;

    printf( "**** Run test case 2 on branch 2 => Check INS_004 with inflexion value NULL.\n");

    // -----
    // Run function
    embedded_localtime(&rawtime, timeinfo);
}


static void test_embedded_localtime_BR3_CS3( void )
{
    // Test case 3 : Full branch 3 test.

    // Parameters
    time_t      rawtime = time(NULL);
    struct tm   timeinfo;

    printf( "**** Run test case 3 on branch 3 => Full branch test.\n");

    // -----
    // Run function
    embedded_localtime(&rawtime, &timeinfo);
}
