//!
//! @file test_pars_raised_error.c
//! @author jbruel
//! @date 11/02/19
//!

#include <np.h>
#include <stdio.h>
#include <jsmn.h>
#include "file_handling/pars_raised_error.h"
#include "test_pars_raised_error.h"

int mock_jsmn_parse_minus_one(__attribute__((unused)) jsmn_parser *parser,
                              __attribute__((unused)) const char *js,
                              __attribute__((unused)) size_t len,
                              __attribute__((unused)) jsmntok_t *tokens,
                              __attribute__((unused)) unsigned int num_tokens)
{
    return (-1);
}

int mock_jsmn_parse_JSMN_UNDEFINED(__attribute__((unused)) jsmn_parser *parser,
                                   __attribute__((unused)) const char *js,
                                   __attribute__((unused)) size_t len,
                                   jsmntok_t *tokens,
                                   __attribute__((unused)) unsigned int num_tokens)
{
    (&tokens)[0]->type = JSMN_UNDEFINED;
    return (1);
}

// ------------------------- STARTING TESTS -------------------------

static void test_pars_raised_error_BR1_CS1( void )
{
    // Test case 1 : INS_009 with inflexion value NULL.

    // Parameters
    bool            ret = false; // Return status
    char            *in = "0123456789"; // Input data.
    size_t          in_size = strlen("0123456789"); // Input data size.
    struct report   *raised_error = NULL; // Faillure struct to load.

    printf( "**** Run test case 1 on branch 1 => Check INS_009 with inflexion value NULL.\n");

    // -----
    // Run function
    ret = pars_raised_error(in, in_size, raised_error);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_pars_raised_error_BR2_CS2( void )
{
    // Test case 2 : INS_010 with inflexion value -1.

    // Parameters
    bool            ret = false; // Return status
    char            *in = "0123456789"; // Input data.
    size_t          in_size = strlen("0123456789"); // Input data size.
    struct report   raised_error; // Faillure struct to load.

    printf( "**** Run test case 2 on branch 2 => Check INS_010 with inflexion value -1.\n");

    // -----
    // Mocks
    // Link mock jsmn_parse with -1 value for INS_013
    np_mock(jsmn_parse, mock_jsmn_parse_minus_one);

    // -----
    // Run function
    ret = pars_raised_error(in, in_size, &raised_error);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_pars_raised_error_BR3_CS3( void )
{
    // Test case 3 : INS_011 with inflexion value JSMN_UNDEFINED.

    // Parameters
    bool            ret = false; // Return status
    char            *in = "0123456789"; // Input data.
    size_t          in_size = strlen("0123456789"); // Input data size.
    struct report   raised_error; // Faillure struct to load.

    printf( "**** Run test case 3 on branch 3 => Check INS_011 with inflexion value JSMN_UNDEFINED.\n");

    // -----
    // Mocks
    // Link mock jsmn_parse with JSMN_UNDEFINED value for INS_014
    np_mock(jsmn_parse, mock_jsmn_parse_JSMN_UNDEFINED);

    // -----
    // Run function
    ret = pars_raised_error(in, in_size, &raised_error);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_pars_raised_error_FULL_BR_CS4( void )
{
    // Test case 4 :Full branch.

    // Parameters
    bool            ret = false; // Return status
    char            *in = "{toto:\"test\"}"; // Input data.
    size_t          in_size = strlen("{toto:\"test\"}"); // Input data size.
    struct report   raised_error; // Faillure struct to load.

    printf( "**** Run test case 4 on full branch => Check full usecase on function.\n");

    // -----
    // Run function
    ret = pars_raised_error(in, in_size, &raised_error);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}

static void test_pars_raised_error_FULL_BR2_CS5( void )
{
    // Test case 5 :Full branch.

    // Parameters
    bool            ret = false; // Return status
    char            *in = "{Id_plane:\"0\", Date:\"0\", Type_plane:\"0\", Nb_failures:\"0\", failures:{Id_failure:\"0\", Date:\"0\", Id_component:\"0\", Level_criticity:\"0\", Comment_failure_size:\"4\", Comment_failure:\"test\"}}"; // Input data.
    size_t          in_size = strlen("{Id_plane:\"0\", Date:\"0\", Type_plane:\"0\", Nb_failures:\"0\", failures:{Id_failure:\"0\", Date:\"0\", Id_component:\"0\", Level_criticity:\"0\", Comment_failure_size:\"4\", Comment_failure:\"test\"}}"); // Input data size.
    struct report   raised_error; // Faillure struct to load.

    printf( "**** Run test case 5 on full branch => Check full options handle by pars_raised_error.\n");

    // -----
    // Run function
    ret = pars_raised_error(in, in_size, &raised_error);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}

static void test_pars_raised_error_FULL_BR3_CS6( void )
{
    // Test case 6 :Full branch.

    // Parameters
    bool            ret = false; // Return status
    char            *in = "{Id_failure:\"0\", Date:\"0\", Id_component:\"0\", Level_criticity:\"0\", Comment_failure_size:\"4\", Comment_failure:\"test\"}"; // Input data.
    size_t          in_size = strlen("{Id_failure:\"0\", Date:\"0\", Id_component:\"0\", Level_criticity:\"0\", Comment_failure_size:\"4\", Comment_failure:\"test\"}"); // Input data size.
    struct report   raised_error; // Faillure struct to load.

    printf( "**** Run test case 6 on full branch => Check full options handle by pars_raised_error with faillures.\n");

    // -----
    // Run function
    ret = pars_raised_error(in, in_size, &raised_error);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}

static void test_pars_raised_error_BR1_CS7( void )
{
    // Test case 7 : NUll ptr test.

    // Parameters
    bool            ret = false; // Return status
    char            *in = NULL; // Input data.
    size_t          in_size = 0; // Input data size.
    struct report   raised_error; // Faillure struct to load.

    printf( "**** Run test case 7 on branch 1 => Check null ptr.\n");

    // -----
    // Run function
    ret = pars_raised_error(in, in_size, &raised_error);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_pars_raised_error_BR12_CS8( void )
{
    // Test case 5 :Full branch.

    // Parameters
    bool            ret = false; // Return status
    char            *in = "{Id_plane:\"0\", Date:\"0\", Type_plane:\"0\", Nb_failures:\"0\", failures:[{Id_failure:\"0\", Date:\"0\", Id_component:\"0\", Level_criticity:\"0\", Comment_failure_size:\"4\", Comment_failure:\"test\"}]}"; // Input data.
    size_t          in_size = strlen("{Id_plane:\"0\", Date:\"0\", Type_plane:\"0\", Nb_failures:\"0\", failures:[{Id_failure:\"0\", Date:\"0\", Id_component:\"0\", Level_criticity:\"0\", Comment_failure_size:\"4\", Comment_failure:\"test\"}]}"); // Input data size.
    struct report   raised_error; // Faillure struct to load.

    printf( "**** Run test case 8 on full branch => Check full branch 12.\n");

    // -----
    // Run function
    ret = pars_raised_error(in, in_size, &raised_error);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}