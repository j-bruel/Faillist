//!
//! @file test_write_failure.c
//! @author jbruel
//! @date 04/03/19
//!

#include <np.h>
#include <stdio.h>
#include "report/faillure/write_failure.h"
#include "report/faillure/write_failure_date.h"
#include "report/faillure/id_component_failure/write_id_component_failure.h"
#include "report/faillure/failure_id/write_failure_id.h"
#include "test_write_failure.h"

bool    mock_write_id_component_failure_false(__attribute__((unused)) int fd,
                                              __attribute__((unused)) unsigned int id_component)
{
    return (false);
}

bool    mock_write_id_component_failure_true(__attribute__((unused)) int fd,
                                             __attribute__((unused)) unsigned int id_component)
{
    return (true);
}

bool    mock_write_failure_date_false(__attribute__((unused)) int fd,
                                      __attribute__((unused)) unsigned int date)
{
    return (false);
}

bool    mock_write_failure_date_true(__attribute__((unused)) int fd,
                                     __attribute__((unused)) unsigned int date)
{
    return (true);
}

bool    mock_write_failure_id_false(__attribute__((unused)) int fd,
                                    __attribute__((unused)) size_t idx,
                                    __attribute__((unused)) unsigned int failure_id)
{
    return (false);
}

bool    mock_write_failure_id_true(__attribute__((unused)) int fd,
                                   __attribute__((unused)) size_t idx,
                                   __attribute__((unused)) unsigned int failure_id)
{
    return (true);
}

// ------------------------- STARTING TESTS -------------------------

static void test_write_failure_BR1_CS1( void )
{
    // Test case 1 : INS_003 with inflexion value NULL.

    // Parameters
    int             fd = 1; // File directory.
    size_t          idx = 0; // Failure index.
    struct failure  *failure = NULL; // Failure information.
    bool            ret = false; // Return status

    printf( "**** Run test case 1 on branch 1 => Check INS_003 with inflexion value NULL.\n");

    // -----
    // Run function
    ret = write_failure(fd, idx, failure);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_write_failure_BR2_CS2( void )
{
    // Test case 2 : INS_004 with inflexion value 1000.

    // Parameters
    int             fd = 1; // File directory.
    size_t          idx = 1000; // Failure index.
    struct failure  failure; // Failure information.
    bool            ret = false; // Return status

    printf( "**** Run test case 2 on branch 2 => Check INS_004 with inflexion value 10000.\n");

    // -----
    // Run function
    ret = write_failure(fd, idx, &failure);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_write_failure_BR3_CS3( void )
{
    // Test case 3 : INS_006 with inflexion value 1.

    // Parameters
    int             fd = 1; // File directory.
    size_t          idx = 1; // Failure index.
    struct failure  failure; // Failure information.
    bool            ret = false; // Return status

    printf( "**** Run test case 3 on branch 3 => INS_006 with inflexion value 1.\n");

    failure.id_failure = 0;
    failure.date = 0;
    failure.id_component = 0;
    failure.level_criticity = 0;
    failure.comment_failure_size = 0;
    memset(failure.comment_failure, '\0', MAX_COMMENT_SIZE);
    // -----
    // Run function
    ret = write_failure(fd, idx, &failure);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_write_failure_BR4_CS4( void )
{
    // Test case 4 : INS_006 with inflexion value 0.

    // Parameters
    int             fd = 1; // File directory.
    size_t          idx = 0; // Failure index.
    struct failure  failure; // Failure information.
    bool            ret = false; // Return status

    printf( "**** Run test case 4 on branch 4 => INS_006 with inflexion value 0.\n");

    failure.id_failure = 0;
    failure.date = 0;
    failure.id_component = 0;
    failure.level_criticity = 0;
    failure.comment_failure_size = 0;
    memset(failure.comment_failure, '\0', MAX_COMMENT_SIZE);
    // -----
    // Run function
    ret = write_failure(fd, idx, &failure);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_write_failure_BR5_CS5( void )
{
    // Test case 5 : INS_008 with inflexion value false.

    // Parameters
    int             fd = 1; // File directory.
    size_t          idx = 0; // Failure index.
    struct failure  failure; // Failure information.
    bool            ret = false; // Return status

    printf( "**** Run test case 5 on branch 5 => INS_008 with inflexion value false.\n");

    failure.id_failure = 0;
    failure.date = 0;
    failure.id_component = 0;
    failure.level_criticity = 0;
    failure.comment_failure_size = 0;
    memset(failure.comment_failure, '\0', MAX_COMMENT_SIZE);

    // -----
    // Mocks
    // Link mock mock_write_failure_id_false with false value for INS_008
    np_mock(write_failure_id, mock_write_failure_id_false);

    // -----
    // Run function
    ret = write_failure(fd, idx, &failure);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_write_failure_BR6_CS6( void )
{
    // Test case 6 : INS_009 with inflexion value false.

    // Parameters
    int             fd = 1; // File directory.
    size_t          idx = 0; // Failure index.
    struct failure  failure; // Failure information.
    bool            ret = false; // Return status

    printf( "**** Run test case 6 on branch 6 => INS_009 with inflexion value false.\n");

    failure.id_failure = 0;
    failure.date = 0;
    failure.id_component = 0;
    failure.level_criticity = 0;
    failure.comment_failure_size = 0;
    memset(failure.comment_failure, '\0', MAX_COMMENT_SIZE);

    // -----
    // Mocks
    // Link mock mock_write_failure_id_true with true value for INS_008
    np_mock(write_failure_id, mock_write_failure_id_true);
    // Link mock write_failure_date with false value for INS_009
    np_mock(write_failure_date, mock_write_failure_date_false);

    // -----
    // Run function
    ret = write_failure(fd, idx, &failure);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_write_failure_BR7_CS7( void )
{
    // Test case 7 : INS_010 with inflexion value false.

    // Parameters
    int             fd = 1; // File directory.
    size_t          idx = 0; // Failure index.
    struct failure  failure; // Failure information.
    bool            ret = false; // Return status

    printf( "**** Run test case 7 on branch 7 => INS_010 with inflexion value false.\n");

    failure.id_failure = 0;
    failure.date = 0;
    failure.id_component = 0;
    failure.level_criticity = 0;
    failure.comment_failure_size = 0;
    memset(failure.comment_failure, '\0', MAX_COMMENT_SIZE);

    // -----
    // Mocks
    // Link mock mock_write_failure_id_true with true value for INS_008
    np_mock(write_failure_id, mock_write_failure_id_true);
    // Link mock write_failure_date with true value for INS_009
    np_mock(write_failure_date, mock_write_failure_date_true);
    // Link mock mock_write_id_component_failure_false with false value for INS_010
    np_mock(write_id_component_failure, mock_write_id_component_failure_false);

    // -----
    // Run function
    ret = write_failure(fd, idx, &failure);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_write_failure_BR8_CS8( void )
{
    // Test case 8 : INS_012 with inflexion value 11.

    // Parameters
    int             fd = 1; // File directory.
    size_t          idx = 0; // Failure index.
    struct failure  failure; // Failure information.
    bool            ret = false; // Return status

    printf( "**** Run test case 8 on branch 8 => INS_012 with inflexion value 11.\n");

    failure.id_failure = 0;
    failure.date = 0;
    failure.id_component = 0;
    failure.level_criticity = 11;
    failure.comment_failure_size = 0;
    memset(failure.comment_failure, '\0', MAX_COMMENT_SIZE);

    // -----
    // Mocks
    // Link mock mock_write_failure_id_true with true value for INS_008
    np_mock(write_failure_id, mock_write_failure_id_true);
    // Link mock write_failure_date with true value for INS_009
    np_mock(write_failure_date, mock_write_failure_date_true);
    // Link mock mock_write_id_component_failure_false with true value for INS_010
    np_mock(write_id_component_failure, mock_write_id_component_failure_true);

    // -----
    // Run function
    ret = write_failure(fd, idx, &failure);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_write_failure_BR9_CS9( void )
{
    // Test case 9 : INS_017 with inflexion value 0.

    // Parameters
    int             fd = 1; // File directory.
    size_t          idx = 0; // Failure index.
    struct failure  failure; // Failure information.
    bool            ret = false; // Return status

    printf( "**** Run test case 9 on branch 9 => INS_017 with inflexion value 0.\n");

    failure.id_failure = 0;
    failure.date = 0;
    failure.id_component = 0;
    failure.level_criticity = 1;
    failure.comment_failure_size = 0;
    memset(failure.comment_failure, '\0', MAX_COMMENT_SIZE);

    // -----
    // Mocks
    // Link mock mock_write_failure_id_true with true value for INS_008
    np_mock(write_failure_id, mock_write_failure_id_true);
    // Link mock write_failure_date with true value for INS_009
    np_mock(write_failure_date, mock_write_failure_date_true);
    // Link mock mock_write_id_component_failure_false with true value for INS_010
    np_mock(write_id_component_failure, mock_write_id_component_failure_true);

    // -----
    // Run function
    ret = write_failure(fd, idx, &failure);

    // -----
    // Check output parameters
    NP_ASSERT_FALSE(ret);
}

static void test_write_failure_BR10_CS10( void )
{
    // Test case 10 : INS_020 with inflexion value 1000.

    // Parameters
    int             fd = 1; // File directory.
    size_t          idx = 0; // Failure index.
    struct failure  failure; // Failure information.
    bool            ret = false; // Return status

    printf( "**** Run test case 10 on branch 10 => INS_020 with inflexion value 1000 but comment under 1000.\n");

    failure.id_failure = 0;
    failure.date = 0;
    failure.id_component = 0;
    failure.level_criticity = 1;
    failure.comment_failure_size = 1000;
    memset(failure.comment_failure, '\0', MAX_COMMENT_SIZE);

    // -----
    // Mocks
    // Link mock mock_write_failure_id_true with true value for INS_008
    np_mock(write_failure_id, mock_write_failure_id_true);
    // Link mock write_failure_date with true value for INS_009
    np_mock(write_failure_date, mock_write_failure_date_true);
    // Link mock mock_write_id_component_failure_false with true value for INS_010
    np_mock(write_id_component_failure, mock_write_id_component_failure_true);

    // -----
    // Run function
    ret = write_failure(fd, idx, &failure);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}

static void test_write_failure_BR11_CS11( void )
{
    // Test case 11 : INS_020 with inflexion value 1.

    // Parameters
    int             fd = 1; // File directory.
    size_t          idx = 0; // Failure index.
    struct failure  failure; // Failure information.
    bool            ret = false; // Return status

    printf( "**** Run test case 11 on branch 11 => INS_020 with inflexion value 1.\n");

    failure.id_failure = 0;
    failure.date = 0;
    failure.id_component = 0;
    failure.level_criticity = 1;
    failure.comment_failure_size = 1;
    memset(failure.comment_failure, '\0', MAX_COMMENT_SIZE);
    failure.comment_failure[0] = 'a';

    // -----
    // Mocks
    // Link mock mock_write_failure_id_true with true value for INS_008
    np_mock(write_failure_id, mock_write_failure_id_true);
    // Link mock write_failure_date with true value for INS_009
    np_mock(write_failure_date, mock_write_failure_date_true);
    // Link mock mock_write_id_component_failure_false with true value for INS_010
    np_mock(write_id_component_failure, mock_write_id_component_failure_true);

    // -----
    // Run function
    ret = write_failure(fd, idx, &failure);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}

static void test_write_failure_BR10_CS12( void )
{
    // Test case 12 : INS_020 with inflexion value 1000.

    // Parameters
    int             fd = 1; // File directory.
    size_t          idx = 0; // Failure index.
    struct failure  failure; // Failure information.
    bool            ret = false; // Return status

    printf( "**** Run test case 12 on branch 9 => INS_020 with inflexion value 1000 and comment overflow.\n");

    failure.id_failure = 0;
    failure.date = 0;
    failure.id_component = 0;
    failure.level_criticity = 1;
    failure.comment_failure_size = 1000;
    memset(failure.comment_failure, 'a', MAX_COMMENT_SIZE);
    failure.comment_failure[1000] = '\0';

    // -----
    // Mocks
    // Link mock mock_write_failure_id_true with true value for INS_008
    np_mock(write_failure_id, mock_write_failure_id_true);
    // Link mock write_failure_date with true value for INS_009
    np_mock(write_failure_date, mock_write_failure_date_true);
    // Link mock mock_write_id_component_failure_false with true value for INS_010
    np_mock(write_id_component_failure, mock_write_id_component_failure_true);

    // -----
    // Run function
    ret = write_failure(fd, idx, &failure);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}

static void test_write_failure_BR11_CS13( void )
{
    // Test case 13 : INS_020 with inflexion value 1.

    // Parameters
    int             fd = 1; // File directory.
    size_t          idx = 0; // Failure index.
    struct failure  failure; // Failure information.
    bool            ret = false; // Return status

    printf( "**** Run test case 13 on branch 11 => INS_020 with inflexion value 1 and comment overflow size.\n");

    failure.id_failure = 0;
    failure.date = 0;
    failure.id_component = 0;
    failure.level_criticity = 1;
    failure.comment_failure_size = 1;
    memset(failure.comment_failure, '\0', MAX_COMMENT_SIZE);
    memset(failure.comment_failure, 'a', MAX_COMMENT_SIZE - 1);

    // -----
    // Mocks
    // Link mock mock_write_failure_id_true with true value for INS_008
    np_mock(write_failure_id, mock_write_failure_id_true);
    // Link mock write_failure_date with true value for INS_009
    np_mock(write_failure_date, mock_write_failure_date_true);
    // Link mock mock_write_id_component_failure_false with true value for INS_010
    np_mock(write_id_component_failure, mock_write_id_component_failure_true);

    // -----
    // Run function
    ret = write_failure(fd, idx, &failure);

    // -----
    // Check output parameters
    NP_ASSERT_TRUE(ret);
}