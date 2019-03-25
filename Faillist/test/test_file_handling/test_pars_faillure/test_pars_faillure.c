//!
//! @file test_pars_faillure.c
//! @author jbruel
//! @date 11/02/19
//!

#include <np.h>
#include <stdio.h>
#include <jsmn.h>
#include "file_handling/pars_faillure.h"
#include "test_pars_faillure.h"

int mock_jsmn_parse_zero(__attribute__((unused)) jsmn_parser *parser,
                         __attribute__((unused)) const char *js,
                         __attribute__((unused)) size_t len,
                         __attribute__((unused)) jsmntok_t *tokens,
                         __attribute__((unused)) unsigned int num_tokens)
{
    return (0);
}

int mock_jsmn_parse_JSMN_OBJECT(__attribute__((unused)) jsmn_parser *parser,
                                __attribute__((unused)) const char *js,
                                __attribute__((unused)) size_t len,
                                jsmntok_t *tokens,
                                __attribute__((unused)) unsigned int num_tokens)
{
    (&tokens)[0]->type = JSMN_UNDEFINED;
    return (1);
}

// ------------------------- STARTING TESTS -------------------------

    static void test_pars_faillure_BR1_CS1( void )
{
    // Test case 1 : INS_006 with inflexion value NULL.

    // Parameters
    bool            ret = false; // Return status
    char            *in = NULL; // Input data.
    size_t          in_size = 10; // Input data size.
    struct failure  faillure; // Faillure struct to load.

    printf( "**** Run test case 1 on branch 1 => Check INS_008 with inflexion value NULL.\n");

    // -----
    // Run function
    ret = pars_faillure(in, in_size, &faillure);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_pars_faillure_BR2_CS2( void )
{
    // Test case 2 : INS_007 with inflexion value 0.

    // Parameters
    bool            ret = false; // Return status
    char            *in = ""; // Input data.
    size_t          in_size = 0; // Input data size.
    struct failure  faillure; // Faillure struct to load.

    printf( "**** Run test case 2 on branch 2 => Check INS_009 with inflexion value 0.\n");

    // -----
    // Run function
    ret = pars_faillure(in, in_size, &faillure);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_pars_faillure_BR3_CS3( void )
{
    // Test case 3 : INS_012 with inflexion value NULL.

    // Parameters
    bool            ret = false; // Return status
    char            *in = "0123456789"; // Input data.
    size_t          in_size = 10; // Input data size.
    struct failure  *faillure = NULL; // Faillure struct to load.

    printf( "**** Run test case 3 on branch 3 => Check INS_012 with inflexion value NULL.\n");

    // -----
    // Run function
    ret = pars_faillure(in, in_size, faillure);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_pars_faillure_BR4_CS4( void )
{
    // Test case 4 : INS_013 with inflexion value 0.

    // Parameters
    bool            ret = false; // Return status
    char            *in = "0123456789"; // Input data.
    size_t          in_size = 10; // Input data size.
    struct failure  faillure; // Faillure struct to load.

    printf( "**** Run test case 4 on branch 4 => Check INS_013 with inflexion value 0.\n");

    // -----
    // Mocks
    // Link mock jsmn_parse with 0 value for INS_013
    np_mock(jsmn_parse, mock_jsmn_parse_zero);

    // -----
    // Run function
    ret = pars_faillure(in, in_size, &faillure);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_pars_faillure_BR5_CS5( void )
{
    // Test case 5 : INS_014 with inflexion value JSMN_UNDEFINED.

    // Parameters
    bool            ret = false; // Return status
    char            *in = "0123456789"; // Input data.
    size_t          in_size = 10; // Input data size.
    struct failure  faillure; // Faillure struct to load.

    printf( "**** Run test case 5 on branch 5 => Check INS_014 with inflexion value JSMN_UNDEFINED.\n");

    // -----
    // Mocks
    // Link mock jsmn_parse with JSMN_UNDEFINED value for INS_014
    np_mock(jsmn_parse, mock_jsmn_parse_JSMN_OBJECT);


    // -----
    // Run function
    ret = pars_faillure(in, in_size, &faillure);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_pars_faillure_FULL_BR_CS6( void )
{
    // Test case 5 :Full branch.

    // Parameters
    bool            ret = false; // Return status
    char            *in = "{toto:\"test\"}"; // Input data.
    size_t          in_size = strlen("{toto:\"test\"}"); // Input data size.
    struct failure  faillure; // Faillure struct to load.

    printf( "**** Run test case 6 on full branch => Check full usecase on function.\n");

    // -----
    // Run function
    ret = pars_faillure(in, in_size, &faillure);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}

static void test_pars_faillure_FULL_BR2_CS7( void )
{
    // Test case 5 :Full branch.

    // Parameters
    bool            ret = false; // Return status
    char            *in = "{Id_failure:\"0\", Date:\"0\", Id_component:\"0\", Level_criticity:\"0\", Comment_failure_size:\"4\", Comment_failure:\"test\"}"; // Input data.
    size_t          in_size = strlen("{Id_failure:\"0\", Date:\"0\", Id_component:\"0\", Level_criticity:\"0\", Comment_failure_size:\"4\", Comment_failure:\"test\"}"); // Input data size.
    struct failure  faillure; // Faillure struct to load.

    printf( "**** Run test case 7 on full branch => Check full options handle by pars_faillure.\n");

    // -----
    // Run function
    ret = pars_faillure(in, in_size, &faillure);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}

static void test_pars_faillure_FULL_BR2_CS8( void )
{
    // Test case 8 : Full branch with errors.

    // Parameters
    bool            ret = false; // Return status
    char            *in = "{Id_failure:\"0\", Date:\"0g\", Id_component:\"0\", Level_criticity:\"0g\", Comment_failure_size:\"g\", Comment_failure:\"test\"}"; // Input data.
    size_t          in_size = strlen("{Id_failure:\"0g\", Date:\"0\", Id_component:\"0\", Level_criticity:\"0g\", Comment_failure_size:\"g\", Comment_failure:\"test\"}"); // Input data size.
    struct failure  faillure; // Faillure struct to load.

    printf( "**** Run test case 8 on full branch => Check full with erros.\n");

    // -----
    // Run function
    ret = pars_faillure(in, in_size, &faillure);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}