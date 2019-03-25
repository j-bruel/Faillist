//!
//! @file test_write_failure_id.h
//! @author jbruel
//! @date 04/03/19
//!

#include <np.h>
#include <stdio.h>
#include "report/faillure/failure_id/write_failure_id.h"
#include "test_write_failure_id.h"

// ------------------------- STARTING TESTS -------------------------

static void test_write_failure_id_BR1_CS1( void )
{
    // Test case 1 : INS_003 with inflexion value 10000.

    printf( "**** Run test case 1 on branch 1 => Check INS_003 with inflexion value 10000.\n");

    // -----
    // Run function
    NP_ASSERT_FALSE(write_failure_id(1 ,0, 10000));
}

static void test_write_failure_id_BR2_CS2( void )
{
    // Test case 1 : Full branch 2 & 4 check.

    printf( "**** Run test case 2 on branch 2 & 4 => Check full branch.\n");

    // -----
    // Run function
    NP_ASSERT_TRUE(write_failure_id(1, 0, 4097));
}

static void test_write_failure_id_BR3_CS3( void )
{
    // Test case 1 : Branch 3 full.

    printf( "**** Run test case 3 on branch 3 => Check full branch.\n");

    // -----
    // Run function
    NP_ASSERT_FALSE(write_failure_id(1, 0, 0));
}