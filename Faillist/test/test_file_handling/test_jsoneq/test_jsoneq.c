//!
//! @file test_jsoneq.c
//! @author jbruel
//! @date 11/02/19
//!

#include <np.h>
#include <stdio.h>
#include "file_handling/jsoneq.h"
#include "test_jsoneq.h"

// ------------------------- STARTING TESTS -------------------------

static void test_jsoneq_BR1_CS1( void )
{
    // Test case 1 : INS_001 with inflexion value not equal JSMN_PRIMITIVE.

    // Parameters
    bool        ret = false; // Return status
    jsmntok_t   tok = {JSMN_UNDEFINED, 0, 0, 0}; // Token indicator.

    printf( "**** Run test case 1 on branch 1 => Check INS_001 with inflexion value NULL.\n");

    // -----
    // Run function
    ret = jsoneq(NULL, &tok, "");

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_jsoneq_BR2_CS2( void )
{
    // Test case 2 : INS_002 with inflexion value NULL.

    // Parameters
    bool    ret = false; // Return status

    printf( "**** Run test case 2 on branch 2 => Check INS_002 with inflexion value NULL.\n");

    // -----
    // Run function
    ret = jsoneq("", NULL, "");

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}


static void test_jsoneq_BR3_CS3( void )
{
    // Test case 3 : INS_003 with inflexion value NULL.

    // Parameters
    bool        ret = false; // Return status
    jsmntok_t   tok = {JSMN_UNDEFINED, 0, 0, 0}; // Token indicator.

    printf( "**** Run test case 3 on branch 3 => Check INS_003 with inflexion value NULL.\n");

    // -----
    // Run function
    ret = jsoneq("", &tok, NULL);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_jsoneq_BR4_CS4( void )
{
    // Test case 4 : INS_005 with inflexion value false.

    // Parameters
    const char  *json = ""; // All input file.
    jsmntok_t   tok = {JSMN_UNDEFINED, 0, 0, 0}; // Token indicator.
    const char  *s = ""; // Input searching string.
    bool    ret = false; // Return status

    printf( "**** Run test case 4 on branch 4 => Check INS_005 with inflexion value not equal JSMN_PRIMITIVE.\n");

    // -----
    // Run function
    ret = jsoneq(json, &tok, s);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_jsoneq_BR5_CS5( void )
{
    // Test case 5 : INS_006 with inflexion value strlen(s) == tok->end - tok->start.

    // Parameters
    const char  *json = ""; // All input file.
    jsmntok_t   tok = {JSMN_PRIMITIVE, 0, 1, 0}; // Token indicator.
    const char  *s = "data\0"; // Input searching string.
    bool    ret = false; // Return status

    printf( "**** Run test case 5 on branch 5 => Check INS_006 with inflexion value not equal strlen(s) == tok->end - tok->start.\n");

    // -----
    // Run function
    ret = jsoneq(json, &tok, s);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_jsoneq_BR6_CS6( void )
{
    // Test case 6 : INS_007 with inflexion value not equal json + tok->start == s.

    // Parameters
    const char  *json = "err"; // All input file.
    jsmntok_t   tok = {JSMN_PRIMITIVE, 0, 4, 0}; // Token indicator.
    const char  *s = "data"; // Input searching string.
    bool    ret = false; // Return status

    printf( "**** Run test case 6 on branch 6 => Check INS_007 with inflexion value not equal json + tok->start == s.\n");

    // -----
    // Run function
    ret = jsoneq(json, &tok, s);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_jsoneq_BR7_CS7( void )
{
    // Test case 7 : Full branch 6 check.

    // Parameters
    const char  *json = "data"; // All input file.
    jsmntok_t   tok = {JSMN_PRIMITIVE, 0, 4, 0}; // Token indicator.
    const char  *s = "data"; // Input searching string.
    bool    ret = false; // Return status

    printf( "**** Run test case 7 on branch 7 => Check full branch 6.\n");

    // -----
    // Run function
    ret = jsoneq(json, &tok, s);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}
