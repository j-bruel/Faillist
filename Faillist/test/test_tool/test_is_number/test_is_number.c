//!
//! @file test_is_number.c
//! @author jbruel
//! @date 04/03/19
//!

#include <np.h>
#include <stdio.h>
#include "tool/is_number.h"
#include "test_is_number.h"

// ------------------------- STARTING TESTS -------------------------

static void test_is_number_BR1_CS1( void )
{
    // Test case 1 : INS_001 with inflexion value NULL.

    // Parameters
    char    *str = NULL; // input string value.
    bool    ret = false; // return value.

    printf( "**** Run test case 1 on branch 1 => Check INS_001 with inflexion value NULL.\n");

    // -----
    // Run function
    ret = is_number(str);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_is_number_BR2_CS2( void )
{
    // Test case 2 : INS_006 with inflexion value 0.

    // Parameters
    char    *str = ""; // input string value.
    bool    ret = false; // return value.

    printf( "**** Run test case 2 on branch 2 => Check INS_006 with inflexion value 0.\n");

    // -----
    // Run function
    ret = is_number(str);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_is_number_BR3_CS3( void )
{
    // Test case 3 : INS_006 with inflexion value 0.

    // Parameters
    char    *str = "a"; // input string value.
    bool    ret = false; // return value.

    printf( "**** Run test case 3 on branch 3 => Check INS_009 with inflexion value false.\n");

    // -----
    // Run function
    ret = is_number(str);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_is_number_BR4_CS4( void )
{
    // Test case 4 : INS_006 with inflexion value 0.

    // Parameters
    char    *str = "1j2"; // input string value.
    bool    ret = false; // return value.

    printf( "**** Run test case 4 on branch 4 => Check INS_009 with inflexion value false.\n");

    // -----
    // Run function
    ret = is_number(str);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_is_number_BR5_CS5( void )
{
    // Test case 5 : Full branch 5 test.

    // Parameters
    char    *str = "5678"; // input string value.
    bool    ret = false; // return value.

    printf( "**** Run test case 5 on branch 5 => Full branch 5 test.\n");

    // -----
    // Run function
    ret = is_number(str);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}
