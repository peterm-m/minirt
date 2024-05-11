#include "munit.h"
#include <stdlib.h>

/*****************************
 * UTILS TESTING
 *****************************/

/*****************************
 * TESTS
 *****************************/

static MunitResult test_empty(const MunitParameter params[], void* fixture)
{
    return (MUNIT_OK);
}

static MunitTest test_suite_tests[] = {
	{(char*)"/array/test_empty", test_empty, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite test_suite = {
    (char*) "", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	return (munit_suite_main(&test_suite, (void*)"test", argc, argv ));
}
