//!
//! @file test_write_id_component_failure.h
//! @author jbruel
//! @date 04/03/19
//!

#include <np.h>
#include <stdio.h>
#include "report/faillure/id_component_failure/write_id_component_failure.h"
#include "test_write_id_component_failure.h"

// ------------------------- STARTING TESTS -------------------------

static void test_write_id_component_failure_BR1_CS1( void )
{
    // Test case 1 : INS_003 with inflexion value 10000.

    printf( "**** Run test case 1 on branch 1 => Check INS_003 with inflexion value -1.\n");

    // -----
    // Run function
    NP_ASSERT_FALSE(write_id_component_failure(-1, 10000));
}

static void test_write_id_component_failure_BR2_CS2( void )
{
    // Test case 2 : INS_003 with inflexion value 10000.

    printf( "**** Run test case 2 on branch 2 => Check INS_003 with inflexion value 10000.\n");

    // -----
    // Run function
    NP_ASSERT_FALSE(write_id_component_failure(1, 10000));
}

static void test_write_id_component_failure_BR3_CS3( void )
{
    // Test case 3 : Full branch 2 & 4 check.

    printf( "**** Run test case 2 on branch 2 & 4 => Check full branch.\n");

    // -----
    // Run function
    NP_ASSERT_TRUE(write_id_component_failure(1, 8197));
}

static void test_write_id_component_failure_BR4_CS4( void )
{
    // Test case 4 : Branch 4 full.

    printf( "**** Run test case 4 on branch 4 => Check full branch.\n");

    // -----
    // Run function
    NP_ASSERT_FALSE(write_id_component_failure(1, 0));
}