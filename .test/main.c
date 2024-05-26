/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:47:27 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/25 13:39:33 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "munit.h"
#include <stdlib.h>
#include "minirt.h"
#include "ray.h"

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

static MunitResult test_sp(const MunitParameter params[])
{
    t_ray   r;
    t_sp    sp;

    r.o = ft_vec3(0.0f, 0.0f, 0.0f);
    r.d = ft_vec3(0.0f, 0.0f, -1.0f);
    r.t = 0.0f;
    sp.center = ft_vec3(0.0f, 0.0f, -5.0f);
    sp.radius = 1.0f;
/////////////// OUT
    ////////// out sphere front
    r.d = ft_normv3(ft_vec3(0.0f, 0.0f, -4.0f));
    r.t = 0.0f;
    munit_assert_true(interseccion_sp(&r, &sp));
    ////////// out sphere back
    r.d = ft_normv3(ft_vec3(0.0f, 0.0f, -6.0f));
    r.t = 0.0f;
    munit_assert_true(interseccion_sp(&r, &sp));
    ////////// out sphere up
    r.d = ft_normv3(ft_vec3(0.0f, 1.0f, -5.0f));
    r.t = 0.0f;
    munit_assert_true(interseccion_sp(&r, &sp));
     ////////// out sphere down
    r.d = ft_normv3(ft_vec3(0.0f, -1.0f, -5.0f));
    r.t = 0.0f;
    munit_assert_true(interseccion_sp(&r, &sp));
    ////////// out sphere left
    r.d = ft_normv3(ft_vec3(1.0f, 0.0f, -5.0f));
    r.t = 0.0f;
    munit_assert_true(interseccion_sp(&r, &sp));
    ////////// out sphere right
    r.d = ft_normv3(ft_vec3(-1.0f, 0.0f, -5.0f));
    r.t = 0.0f;
    munit_assert_true(interseccion_sp(&r, &sp));
/////////////// IN
    sp.center = ft_vec3(0.0f, 0.0f, 0.0f);
    ////////// in sphere front
    r.d = ft_normv3(ft_vec3(0.0f, 0.0f, -1.0f));
    r.t = 0.0f;
    munit_assert_true(interseccion_sp(&r, &sp));
    ////////// in sphere back
    r.d = ft_normv3(ft_vec3(0.0f, 0.0f, 1.0f));
    r.t = 0.0f;
    munit_assert_true(interseccion_sp(&r, &sp));
    ////////// in sphere up
    r.d = ft_normv3(ft_vec3(0.0f, 1.0f, 0.0f));
    r.t = 0.0f;
    munit_assert_true(interseccion_sp(&r, &sp));
     ////////// in sphere down
    r.d = ft_normv3(ft_vec3(0.0f, -1.0f, 0.0f));
    r.t = 0.0f;
    munit_assert_true(interseccion_sp(&r, &sp));
    ////////// in sphere left
    r.d = ft_normv3(ft_vec3(1.0f, 0.0f, 0.0f));
    r.t = 0.0f;
    munit_assert_true(interseccion_sp(&r, &sp));
    ////////// in sphere right
    r.d = ft_normv3(ft_vec3(-1.0f, 0.0f, 0.0f));
    r.t = 0.0f;
    munit_assert_true(interseccion_sp(&r, &sp));
    return (MUNIT_OK);
}


static MunitTest test_suite_tests[] = {
	{(char*)"test_empty", test_empty, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"test_sp", test_sp, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite test_suite = {
    (char*) "", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	return munit_suite_main(&test_suite, (void*)"test", argc, argv );
}
