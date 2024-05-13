/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:47:27 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/13 18:20:04 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "munit.h"
#include <stdlib.h>

/*****************************
 * UTILS
 *****************************/

/*****************************
 * TESTS
 *****************************/

static MunitResult test_empty(const MunitParameter params[], void* fixture)
{
    munit_assert_int('a', == , 'a');
    return (MUNIT_OK);
}

static MunitTest test_suite_tests[] = {
	{(char*)"test_empty", test_empty, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite test_suite = {
    (char*) "", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	return munit_suite_main(&test_suite, (void*)"test", argc, argv );
}
