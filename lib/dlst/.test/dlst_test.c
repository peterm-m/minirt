#include "munit.h"
#include "../ft_dlst.h"
#include <stdlib.h>


int cmp(void const* e1, void const* e2)
{
    int i = *(*((int**)e1));
    int j = *(*((int**)e2));

    if (i < j)
        return -1;
    if (i == j)
        return 0;
    return 1;
}

int zero_if_ptr_eq(void const* e1, void const* e2)
{
    return !(e1 == e2);
}

void* copy(void* e1)
{
    int* cp = (int*)malloc(sizeof(int));
    *cp = *((int*)e1);
    return cp;
}

bool pred1(const void* e)
{
    return *(int*)e == 0;
}

bool pred2(const void* e)
{
    return *(int*)e > 3;
}

void sum_reduce(void* e1, void* e2, void* res)
{
    int i = *(int*)e1;
    int j = *(int*)e2;

    *(int*)res = i + j;
}

void bool_and(void* e1, void* e2, void* res)
{
    bool p = *(bool*)e1;
    bool q = *(bool*)e2;

    *(bool*)res = p && q;
}

/*****************************
 * TESTS
 *****************************/
static MunitResult test_new(const MunitParameter params[], void* fixture)
{
    t_dlst* list1;
    t_dlst* list2;

    ft_dlst_new(&list1);
    ft_dlst_new(&list2);

    munit_assert_ptr_not_null(list1);
    munit_assert_ptr_not_null(list2);

    void* e = NULL;
    ft_dlst_get_first(list1, &e);
    munit_assert_ptr_null(e);

    ft_dlst_get_last(list1, &e);
    munit_assert_ptr_null(e);

    munit_assert_size(0, == , ft_dlst_size(list1));
    munit_assert_ptr_not_equal(list1, list2);

    ft_dlst_destroy(list1);
    ft_dlst_destroy(list2);

    return MUNIT_OK;
}

static MunitResult test_add(const MunitParameter params[], void* fixture)
{
    t_dlst* list1;
    ft_dlst_new(&list1);

    char* s1 = "e1", * s2 = "e2", * s3 = "e3", * s4 = "e4";

    munit_assert_int(LST_OK, == , ft_dlst_add(list1, s1));
    munit_assert_int(LST_OK, == , ft_dlst_add(list1, s2));
    munit_assert_int(LST_OK, == , ft_dlst_add(list1, s3));
    munit_assert_int(LST_OK, == , ft_dlst_add(list1, s4));

    void* e;
    ft_dlst_get_first(list1, &e);
    munit_assert_ptr_not_null(e);

    ft_dlst_get_last(list1, &e);
    munit_assert_ptr_not_null(e);

    ft_dlst_destroy(list1);

    return MUNIT_OK;
}

static MunitResult test_add_last(const MunitParameter params[], void* fixture)
{
    t_dlst* list1;
    ft_dlst_new(&list1);

    int a = 8;
    int b = 3;
    int c = 20;
    int d = 1;

    int append = 90;

    ft_dlst_add(list1, &a);
    ft_dlst_add(list1, &b);
    ft_dlst_add(list1, &c);
    ft_dlst_add(list1, &d);

    munit_assert_size(4, ==, ft_dlst_size(list1));

    int* last;
    ft_dlst_get_last(list1, (void*)&last);
    munit_assert_int(d, == , *last);

    ft_dlst_add_last(list1, &append);
    munit_assert_size(5, == , ft_dlst_size(list1));

    ft_dlst_get_last(list1, (void*)&last);
    munit_assert_int(append, == , *last);

    ft_dlst_destroy(list1);

    return MUNIT_OK;
}

static MunitResult test_add_first(const MunitParameter params[], void* fixture)
{
    t_dlst* list1;
    ft_dlst_new(&list1);

    int a = 8;
    int b = 3;
    int c = 20;
    int d = 1;

    int prepend = 90;

    ft_dlst_add(list1, &a);
    ft_dlst_add(list1, &b);
    ft_dlst_add(list1, &c);
    ft_dlst_add(list1, &d);

    munit_assert_size(4, == , ft_dlst_size(list1));

    int* first;
    ft_dlst_get_first(list1, (void*)&first);
    munit_assert_int(a, == , *first);

    ft_dlst_add_first(list1, &prepend);
    munit_assert_size(5, == , ft_dlst_size(list1));

    ft_dlst_get_first(list1, (void*)&first);
    munit_assert_int(prepend, == , *first);

    ft_dlst_destroy(list1);

    return MUNIT_OK;
}

static MunitResult test_contains(const MunitParameter params[], void* fixture)
{
    t_dlst* list1;
    ft_dlst_new(&list1);

    int a = 8;
    int b = 3;
    int c = 20;
    int d = 7;
    int e = 32;

    ft_dlst_add(list1, &a);
    ft_dlst_add(list1, &b);
    ft_dlst_add(list1, &b);
    ft_dlst_add(list1, &c);
    ft_dlst_add(list1, &d);

    munit_assert_size(2, == , ft_dlst_contains(list1, &b));
    munit_assert_size(1, == , ft_dlst_contains(list1, &d));
    munit_assert_size(0, == , ft_dlst_contains(list1, &e));

    ft_dlst_destroy(list1);

    return MUNIT_OK;
}

static MunitResult test_index_of(const MunitParameter params[], void* fixture)
{
    t_dlst* list1;
    ft_dlst_new(&list1);

    int a = 8;
    int b = 3;
    int c = 20;
    int d = 1;

    ft_dlst_add(list1, &a);
    ft_dlst_add(list1, &b);
    ft_dlst_add(list1, &c);
    ft_dlst_add(list1, &d);

    size_t idx;
    ft_dlst_index_of(list1, &a, zero_if_ptr_eq, &idx);
    munit_assert_size(0, == , idx);

    ft_dlst_index_of(list1, &c, zero_if_ptr_eq, &idx);
    munit_assert_size(2, == , idx);

    ft_dlst_destroy(list1);

    return MUNIT_OK;
}

static MunitResult test_zip_iter_next(const MunitParameter params[], void* fixture)
{
    t_dlst* list1;
    ft_dlst_new(&list1);

    t_dlst* list2;
    ft_dlst_new(&list2);

    char* a = "a";
    char* e = "e";
    char* c = "c";
    char* g = "g";

    ft_dlst_add(list1, a);
    ft_dlst_add(list1, "b");
    ft_dlst_add(list1, c);
    ft_dlst_add(list1, "d");

    ft_dlst_add(list2, e);
    ft_dlst_add(list2, "f");
    ft_dlst_add(list2, g);

    t_dlst_zip zip;
    ft_dlst_zip_init(&zip, list1, list2);

    size_t i = 0;

    void* e1, * e2;
    while (ft_dlst_zip_next(&zip, &e1, &e2) != LST_ITER_END) {
        if (i == 0) {
            munit_assert_string_equal(a, (char*)e1);
            munit_assert_string_equal(e, (char*)e2);
        }
        if (i == 2) {
            munit_assert_string_equal(c, (char*)e1);
            munit_assert_string_equal(g, (char*)e2);
        }
        i++;
    }
    munit_assert_size(3, == , i);

    ft_dlst_destroy(list1);
    ft_dlst_destroy(list2);

    return MUNIT_OK;
}

static MunitResult test_zip_iter_add(const MunitParameter params[], void* fixture)
{
    t_dlst* list1;
    ft_dlst_new(&list1);

    t_dlst* list2;
    ft_dlst_new(&list2);

    char* a = "a", * b = "b", * c = "c", * d = "d",
        * e = "e", * f = "f", * g = "g";

    ft_dlst_add(list1, a);
    ft_dlst_add(list1, b);
    ft_dlst_add(list1, c);
    ft_dlst_add(list1, d);

    ft_dlst_add(list2, e);
    ft_dlst_add(list2, f);
    ft_dlst_add(list2, g);

    char* h = "h";
    char* i = "i";

    t_dlst_zip zip;
    ft_dlst_zip_init(&zip, list1, list2);

    void* e1, * e2;
    while (ft_dlst_zip_next(&zip, &e1, &e2) != LST_ITER_END) {
        if (strcmp((char*)e1, b) == 0)
            ft_dlst_zip_add(&zip, h, i);
    }

    size_t index;
    munit_assert_size(LST_OK, ==, ft_dlst_index_of(list1, h, zero_if_ptr_eq, &index));
    munit_assert_size(2, ==, index);

    munit_assert_size(LST_OK, ==, ft_dlst_index_of(list2, i, zero_if_ptr_eq, &index));
    munit_assert_size(2, ==, index);

    munit_assert_size(LST_OK, ==, ft_dlst_index_of(list1, c, zero_if_ptr_eq, &index));
    munit_assert_size(3, == , index);

    munit_assert_size(1, ==, ft_dlst_contains(list1, h));
    munit_assert_size(1, == , ft_dlst_contains(list2, i));
    munit_assert_size(5, == , ft_dlst_size(list1));
    munit_assert_size(4, == , ft_dlst_size(list2));

    ft_dlst_zip_init(&zip, list1, list2);
    while (ft_dlst_zip_next(&zip, &e1, &e2) != LST_ITER_END) {
        if (strcmp((char*)e2, g) == 0)
            ft_dlst_zip_add(&zip, "x", "y");
    }

    char* last;
    ft_dlst_get_last(list1, (void*)&last);
    munit_assert_string_equal(d, last);

    ft_dlst_get_last(list2, (void*)&last);
    munit_assert_string_equal("y", last);

    ft_dlst_destroy(list1);
    ft_dlst_destroy(list2);

    return MUNIT_OK;
}

static MunitResult test_zip_iter_remove(const MunitParameter params[], void* fixture)
{
    t_dlst* list1;
    ft_dlst_new(&list1);

    t_dlst* list2;
    ft_dlst_new(&list2);

    ft_dlst_add(list1, "a");
    ft_dlst_add(list1, "b");
    ft_dlst_add(list1, "c");
    ft_dlst_add(list1, "d");

    ft_dlst_add(list2, "e");
    ft_dlst_add(list2, "f");
    ft_dlst_add(list2, "g");

    t_dlst_zip zip;
    ft_dlst_zip_init(&zip, list1, list2);

    void* e1, * e2;
    void* r1, * r2;
    while (ft_dlst_zip_next(&zip, &e1, &e2) != LST_ITER_END) {
        if (strcmp((char*)e1, "b") == 0)
            ft_dlst_zip_remove(&zip, &r1, &r2);
    }
    munit_assert_string_equal("b", r1);
    munit_assert_string_equal("f", r2);
    munit_assert_size(0, == , ft_dlst_contains(list1, "b"));
    munit_assert_size(0, == , ft_dlst_contains(list2, "f"));
    munit_assert_size(3, == , ft_dlst_size(list1));
    munit_assert_size(2, == , ft_dlst_size(list2));

    ft_dlst_destroy(list1);
    ft_dlst_destroy(list2);

    return MUNIT_OK;
}

// static MunitResult test_zip_iter_replace(const MunitParameter params[], void* fixture)
// {
//     t_dlst* list1;
//     ft_dlst_new(&list1);
// 
//     t_dlst* list2;
//     ft_dlst_new(&list2);
// 
//     ft_dlst_add(list1, "a");
//     ft_dlst_add(list1, "b");
//     ft_dlst_add(list1, "c");
//     ft_dlst_add(list1, "d");
// 
//     ft_dlst_add(list2, "e");
//     ft_dlst_add(list2, "f");
//     ft_dlst_add(list2, "g");
// 
//     char* h = "h";
//     char* i = "i";
// 
//     t_dlst_zip zip;
//     ft_dlst_zip_init(&zip, list1, list2);
// 
//     void* e1, * e2;
//     void* r1, * r2;
//     while (ft_dlst_zip_next(&zip, &e1, &e2) != LST_ITER_END) {
//         if (strcmp((char*)e1, "b") == 0)
//             ft_dlst_zip_replace(&zip, h, i, &r1, &r2);
//     }
// 
//     size_t index;
//     munit_assert_size(LST_OK, ==, ft_dlst_index_of(list1, h, zero_if_ptr_eq, &index));
//     munit_assert_size(1, == , index);
// 
//     munit_assert_size(LST_OK, ==, ft_dlst_index_of(list2, i, zero_if_ptr_eq, &index));
//     munit_assert_size(1, == , index);
//     munit_assert_size(1, == , ft_dlst_contains(list1, h));
//     munit_assert_size(1, == , ft_dlst_contains(list2, i));
// 
//     ft_dlst_destroy(list1);
//     ft_dlst_destroy(list2);
// 
//     return MUNIT_OK;
// }

struct lists {
    t_dlst* list1;
    t_dlst* list2;
};


static void* pre_filled_lists(const MunitParameter params[], void* user_data)
{
    struct lists* l = malloc(sizeof(struct lists));

    ft_dlst_new(&(l->list1));
    ft_dlst_new(&(l->list2));

    int* a = (int*)malloc(sizeof(int));
    int* b = (int*)malloc(sizeof(int));
    int* c = (int*)malloc(sizeof(int));
    int* d = (int*)malloc(sizeof(int));

    *a = 1;
    *b = 2;
    *c = 3;
    *d = 4;

    ft_dlst_add(l->list1, a);
    ft_dlst_add(l->list1, b);
    ft_dlst_add(l->list1, c);
    ft_dlst_add(l->list1, d);

    a = (int*)malloc(sizeof(int));
    b = (int*)malloc(sizeof(int));
    c = (int*)malloc(sizeof(int));
    d = (int*)malloc(sizeof(int));

    *a = 5;
    *b = 6;
    *c = 7;
    *d = 8;

    ft_dlst_add(l->list2, a);
    ft_dlst_add(l->list2, b);
    ft_dlst_add(l->list2, c);
    ft_dlst_add(l->list2, d);

    return (void*)l;
}

static void lists_teardown(void* fixture)
{
    struct lists* l = (struct lists*)fixture;
    ft_dlst_destroy_cb(l->list1, free);
    ft_dlst_destroy(l->list2);
    free(l);
}

static MunitResult test_add_all_at(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    ft_dlst_add_all_at(l->list1, l->list2, 2);
    munit_assert_size(4, == , ft_dlst_size(l->list2));
    munit_assert_size(8, == , ft_dlst_size(l->list1));

    int* last;
    ft_dlst_get_last(l->list1, (void*)&last);
    int* l1i4;
    ft_dlst_get_at(l->list1, 4, (void*)&l1i4);
    int* l2i2;
    ft_dlst_get_at(l->list2, 2, (void*)&l2i2);

    munit_assert_int(4, == , *last);
    munit_assert_int(*l1i4, == , *l2i2);

    return MUNIT_OK;
}

static MunitResult test_iter_add(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    int* ins = (int*)malloc(sizeof(int));
    *ins = 32;

    t_dlst_iter iter;
    ft_dlst_iter_init(&iter, l->list1);

    int* el;
    while (ft_dlst_iter_next(&iter, (void*)&el) != LST_ITER_END) {
        if (*el == 3)
            ft_dlst_iter_add(&iter, ins);
    }

    munit_assert_size(5, == , ft_dlst_size(l->list1));

    int* li3;
    ft_dlst_get_at(l->list1, 3, (void*)&li3);

    munit_assert_int(*li3, == , *ins);

    int* li4;
    ft_dlst_get_at(l->list1, 4, (void*)&li4);
    munit_assert_int(4, ==, *li4);

    ft_dlst_iter_init(&iter, l->list1);

    ins = (int*)malloc(sizeof(int));
    *ins = 32;

    while (ft_dlst_iter_next(&iter, (void*)&el) != LST_ITER_END) {
        if (*el == 4) {
            ft_dlst_iter_add(&iter, ins);
        }
    }

    void* e;
    ft_dlst_get_last(l->list1, &e);
    munit_assert_int(*ins, == , *((int*)e));

    return MUNIT_OK;
}

static MunitResult test_iter_remove(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    int* rm;
    ft_dlst_get_at(l->list1, 2, (void*)&rm);

    t_dlst_iter iter;
    ft_dlst_iter_init(&iter, l->list1);

    int* e;
    while (ft_dlst_iter_next(&iter, (void*)&e) != LST_ITER_END) {
        if (*e == 3) {
            ft_dlst_iter_remove(&iter, NULL);
        }
    }
    munit_assert_size(3, == , ft_dlst_size(l->list1));
    munit_assert_size(0, ==, ft_dlst_contains(l->list1, rm));
    free(rm);

    return MUNIT_OK;
}

static MunitResult test_iter_desc_remove(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    t_dlst_iter iter;
    ft_dlst_diter_init(&iter, l->list1);

    int* i;
    while (ft_dlst_diter_next(&iter, (void*)&i) != LST_ITER_END) {
        if (*i == 1 || *i == 3) {
            ft_dlst_diter_remove(&iter, NULL);
            free(i);
        }
    }
    munit_assert_size(2, ==, ft_dlst_size(l->list1));

    int* first;
    ft_dlst_get_first(l->list1, (void*)&first);

    int* last;
    ft_dlst_get_last(l->list1, (void*)&last);

    int* i1;
    ft_dlst_get_at(l->list1, 1, (void*)&i1);

    munit_assert_int(2, == , *first);
    munit_assert_int(4, == , *last);
    munit_assert_int(4, == , *i1);

    return MUNIT_OK;
}

static MunitResult test_iter_desc_add(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    int* a = (int*)malloc(sizeof(int));
    int* b = (int*)malloc(sizeof(int));
    *a = 30;
    *b = 78;

    t_dlst_iter iter;
    ft_dlst_diter_init(&iter, l->list1);

    int* i;
    while (ft_dlst_diter_next(&iter, (void*)&i) != LST_ITER_END) {
        if (*i == 4) // add to tail
            ft_dlst_diter_add(&iter, a);

        if (*i == 3)
            ft_dlst_diter_add(&iter, b);
    }

    munit_assert_size(6, == , ft_dlst_size(l->list1));
    int* el;
    ft_dlst_get_first(l->list1, (void*)&el);
    munit_assert_int(1, == , *el);

    ft_dlst_get_last(l->list1, (void*)&el);
    munit_assert_int(4, == , *el);

    ft_dlst_get_at(l->list1, 2, (void*)&el);
    munit_assert_int(*b, == , *el);

    ft_dlst_get_at(l->list1, 4, (void*)&el);
    munit_assert_int(*a, == , *el);

    return MUNIT_OK;
}

static MunitResult test_reverse(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    int* last_old;
    ft_dlst_get_last(l->list1, (void*)&last_old);

    ft_dlst_reverse(l->list1);

    int* el;
    ft_dlst_get_at(l->list1, 0, (void*)&el);
    munit_assert_int(4, == , *el);

    ft_dlst_get_at(l->list1, 2, (void*)&el);
    munit_assert_int(2, == , *el);

    ft_dlst_get_first(l->list1, (void*)&el);
    munit_assert_ptr_equal(el, last_old);

    return MUNIT_OK;
}

static MunitResult test_to_array(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    int** array;
    ft_dlst_to_array(l->list1, (void*)&array);

    void* e;
    ft_dlst_get_at(l->list1, 0, &e);
    munit_assert_ptr_equal(array[0], e);

    ft_dlst_get_at(l->list1, 2, &e);
    munit_assert_ptr_equal(array[2], e);

    ft_dlst_get_at(l->list1, 3, &e);
    munit_assert_ptr_equal(array[3], e);

    free(array);
    return MUNIT_OK;
}

static MunitResult test_splice_at(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    ft_dlst_splice_at(l->list1, l->list2, 2);

    munit_assert_size(8, == , ft_dlst_size(l->list1));
    munit_assert_size(0, == , ft_dlst_size(l->list2));

    int* el;
    ft_dlst_get_first(l->list1, (void*)&el);
    munit_assert_int(1, == , *el);

    ft_dlst_get_last(l->list1, (void*)&el);
    munit_assert_int(4, == , *el);

    ft_dlst_get_at(l->list1, 2, (void*)&el);
    munit_assert_int(5, == , *el);

    return MUNIT_OK;
}

static MunitResult test_splice(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    ft_dlst_splice(l->list1, l->list2);
    munit_assert_size(8, == , ft_dlst_size(l->list1));
    munit_assert_size(0, == , ft_dlst_size(l->list2));

    int* el;
    ft_dlst_get_last(l->list1, (void*)&el);
    munit_assert_int(8, == , *el);

    ft_dlst_get_first(l->list1, (void*)&el);
    munit_assert_int(1, == , *el);

    ft_dlst_get_at(l->list1, 4, (void*)&el);
    munit_assert_int(5, == , *el);

    return MUNIT_OK;
}

static MunitResult test_add_all(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    ft_dlst_add_all(l->list2, l->list1);

    munit_assert_size(8, == , ft_dlst_size(l->list2));

    int* l1last;
    ft_dlst_get_last(l->list1, (void*)&l1last);

    int* l2last;
    ft_dlst_get_last(l->list2, (void*)&l2last);
    munit_assert_int(*l1last, == , *l2last);

    return MUNIT_OK;
}

static MunitResult test_remove(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    int* e;
    ft_dlst_get_at(l->list1, 1, (void*)&e);
    ft_dlst_remove(l->list1, e, NULL);

    munit_assert_size(3, == , ft_dlst_size(l->list1));
    munit_assert_size(0, ==, ft_dlst_contains(l->list1, e));
    free(e);

    return MUNIT_OK;
}

static MunitResult test_remove_first(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    int* el;
    ft_dlst_remove_first(l->list1, (void*)&el);
    free(el);

    munit_assert_size(3, == , ft_dlst_size(l->list1));

    ft_dlst_get_first(l->list1, (void*)&el);
    munit_assert_int(2, == , *el);

    return MUNIT_OK;
}

static MunitResult test_remove_last(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    int* el;
    ft_dlst_remove_last(l->list1, (void*)&el);
    free(el);
    munit_assert_size(3, == , ft_dlst_size(l->list1));

    munit_assert_int(LST_OK, == , ft_dlst_get_last(l->list1, (void*)&el));
    munit_assert_int(3, == , *el);

    return MUNIT_OK;
}

static MunitResult test_remove_at(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    int* e;
    ft_dlst_remove_at(l->list1, 2, (void*)&e);
    free(e);

    ft_dlst_get_at(l->list1, 2, (void*)&e);
    munit_assert_int(4, == , *e);
    munit_assert_size(3, == , ft_dlst_size(l->list1));
    ft_dlst_remove_at(l->list1, 0, (void*)&e);
    free(e);

    ft_dlst_get_at(l->list1, 0, (void*)&e);
    munit_assert_int(2, == , *e);

    return MUNIT_OK;
}

static MunitResult test_remove_all(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    int* e;
    ft_dlst_get_first(l->list1, (void*)&e);
    munit_assert_int(1, == , *e);

    ft_dlst_remove_all_cb(l->list1, free);
    munit_assert_size(0, == , ft_dlst_size(l->list1));

    e = NULL;
    ft_dlst_get_first(l->list1, (void*)&e);
    munit_assert_ptr_null(e);

    return MUNIT_OK;
}


static MunitResult test_get_last(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    int* e;
    ft_dlst_get_last(l->list1, (void*)&e);
    munit_assert_int(4, == , *e);

    return MUNIT_OK;
}


static MunitResult test_get_at(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    int* e;
    ft_dlst_get_at(l->list1, 1, (void*)&e);
    munit_assert_int(2, == , *e);

    return MUNIT_OK;
}

static MunitResult test_replace_at(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    int* replacement = (int*)malloc(sizeof(int));
    *replacement = 32;

    int* r;
    ft_dlst_replace_at(l->list1, replacement, 2, (void*)&r);
    free(r);

    ft_dlst_get_at(l->list1, 2, (void*)&r);
    munit_assert_ptr_equal(r, replacement);

    return MUNIT_OK;
}

static MunitResult test_copy_deep(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    t_dlst* cp;
    ft_dlst_copy_deep(l->list1, copy, &cp);
    munit_assert_size(4, == , ft_dlst_size(cp));

    int* e;
    ft_dlst_get_at(cp, 2, (void*)&e);

    int* le;
    ft_dlst_get_at(l->list1, 2, (void*)&le);
    munit_assert_int(*e, == , *le);

    ft_dlst_get_at(cp, 2, (void*)&e);
    ft_dlst_get_at(l->list1, 2, (void*)&le);
    munit_assert_ptr_not_equal(e, le);

    ft_dlst_destroy_cb(cp, free);

    return MUNIT_OK;
}

static MunitResult test_sublist(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    t_dlst* sub;
    ft_dlst_sublist(l->list1, 1, 2, &sub);
    munit_assert_size(2, == , ft_dlst_size(sub));

    int* s1;
    ft_dlst_get_at(sub, 1, (void*)&s1);

    int* l2;
    ft_dlst_get_at(l->list1, 2, (void*)&l2);
    munit_assert_int(*s1, ==, *l2);

    ft_dlst_destroy(sub);

    return MUNIT_OK;
}

static MunitResult test_add_at(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    int* ins = (int*)malloc(sizeof(int));
    *ins = 90;

    ft_dlst_add_at(l->list1, ins, 3);
    munit_assert_size(5, == , ft_dlst_size(l->list1));

    int* new;
    ft_dlst_get_at(l->list1, 3, (void*)&new);
    munit_assert_int(*ins, ==, *new);

    return MUNIT_OK;
}

static MunitResult test_copy_shallow(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    t_dlst* cp;
    ft_dlst_copy_shallow(l->list1, &cp);
    munit_assert_size(4, == , ft_dlst_size(cp));

    void* f1;
    void* f2;
    for (int i = 0; i < ft_dlst_size(l->list1); i++) {
        ft_dlst_get_at(cp, i, &f1);
        ft_dlst_get_at(l->list1, i, &f2);
        munit_assert_ptr_equal(f1, f2);
    }
    ft_dlst_destroy(cp);

    return MUNIT_OK;
}

static MunitResult test_mut_filter1(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    munit_assert_size(4, == , ft_dlst_size(l->list1));
    ft_dlst_filter_mut(l->list1, pred1);
    munit_assert_size(0, == , ft_dlst_size(l->list1));

    void* e = NULL;
    ft_dlst_get_first(l->list1, &e);
    munit_assert_ptr_null(e);

    ft_dlst_get_last(l->list1, &e);
    munit_assert_ptr_null(e);

    return MUNIT_OK;
}

static MunitResult test_mut_filter2(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    munit_assert_size(4, == , ft_dlst_size(l->list1));
    ft_dlst_filter_mut(l->list1, pred2);
    munit_assert_size(1, == , ft_dlst_size(l->list1));

    t_dlst_iter iter;
    int* el = NULL;
    int i = 4;
    ft_dlst_iter_init(&iter, l->list1);
    while (ft_dlst_iter_next(&iter, (void*)&el) != LST_ITER_END) {
        munit_assert_int(i++, == , *el);
    }

    return MUNIT_OK;
}

static MunitResult test_filter1(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    t_dlst* filter = NULL;
    ft_dlst_filter(l->list1, pred1, &filter);

    munit_assert_size(4, == , ft_dlst_size(l->list1));
    munit_assert_size(0, == , ft_dlst_size(filter));

    void* e = NULL;
    ft_dlst_get_first(filter, &e);
    munit_assert_ptr_null(e);

    ft_dlst_get_last(filter, &e);
    munit_assert_ptr_null(e);
    free(filter);

    return MUNIT_OK;
}

static MunitResult test_filter2(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    t_dlst* filter = NULL;
    ft_dlst_filter(l->list1, pred2, &filter);

    munit_assert_size(4, == , ft_dlst_size(l->list1));
    munit_assert_size(1, == , ft_dlst_size(filter));

    t_dlst_iter iter;
    int* el = NULL;
    int i = 4;
    ft_dlst_iter_init(&iter, filter);
    while (ft_dlst_iter_next(&iter, (void*)&el) != LST_ITER_END) {
        munit_assert_int(i++, == , *el);
    }

    free(filter);

    return MUNIT_OK;
}

static MunitResult test_reduce1(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;
    int res;

    ft_dlst_reduce(l->list1, sum_reduce, &res);

    munit_assert_int(10, == , res);

    return MUNIT_OK;
}

static MunitResult test_reduce2(const MunitParameter params[], void* fixture)
{
    struct lists* l = (struct lists*)fixture;

    bool res;

    ft_dlst_reduce(l->list1, bool_and, &res);

    munit_assert_true(res);

    return MUNIT_OK;
}


static MunitTest test_suite_tests[] = {
    {(char*)"/list/test_new", test_new, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_add", test_add, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_add_last", test_add_last, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_add_first", test_add_first, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_contains", test_contains, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_index_of", test_index_of, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_zip_iter_next", test_zip_iter_next, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_zip_iter_add", test_zip_iter_add, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_zip_iter_remove", test_zip_iter_remove, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_add_all_at", test_add_all_at, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_iter_add", test_iter_add, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_iter_remove", test_iter_remove, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_iter_desc_remove", test_iter_desc_remove, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_iter_desc_add", test_iter_desc_add, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_reverse", test_reverse, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_to_array", test_to_array, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_splice_at", test_splice_at, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_splice", test_splice, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_add_all", test_add_all, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_remove", test_remove, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_remove_first", test_remove_first, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_remove_last", test_remove_last, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_remove_at", test_remove_at, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_remove_all", test_remove_all, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_get_last", test_get_last, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_get_at", test_get_at, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_replace_at", test_replace_at, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_copy_deep", test_copy_deep, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_sublist", test_sublist, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_add_at", test_add_at, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_copy_shallow", test_copy_shallow, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_mut_filter1", test_mut_filter1, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_mut_filter2", test_mut_filter2, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_filter1", test_filter1, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_filter2", test_filter2, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_reduce1", test_reduce1, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    {(char*)"/list/test_reduce2", test_reduce2, pre_filled_lists, lists_teardown, MUNIT_TEST_OPTION_NONE, NULL},
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite test_suite = {
    (char*)"", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
    return munit_suite_main(&test_suite, (void*)"test", argc, argv);
}