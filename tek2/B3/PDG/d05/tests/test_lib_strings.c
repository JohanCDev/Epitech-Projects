/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** test_string_lib
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(string_init, test_string_init)
{
    string_t s;

    string_init(&s, "Hello");
    cr_assert_str_eq(s.str, "Hello");
    cr_assert_not_null(s.assign_c);
    cr_assert_not_null(s.assign_s);
}

Test(string_init, test_string_init_null)
{
    string_t s;

    string_init(&s, NULL);
    s.str = NULL;
    cr_assert_null(s.str);
    cr_assert_not_null(s.assign_c);
    cr_assert_not_null(s.assign_s);
}

Test(string_destroy, test_string_destroy)
{
    string_t s;

    string_init(&s, "Hello");
    string_destroy(&s);
    cr_assert_null(s.str);
}

Test(assign_c, test_assign_c)
{
    string_t s;

    string_init(&s, "");
    s.assign_c(&s, "Hello");
    cr_assert_str_eq(s.str, "Hello");
}

Test(assign_s, test_assign_s)
{
    string_t s;
    string_t c;

    string_init(&s, "");
    string_init(&c, "lol");
    s.assign_s(&s, &c);
    cr_assert_str_eq(s.str, "lol");
}

Test(append_c, test_append_c)
{
    string_t s;

    string_init(&s, "Hello World,");
    s.append_c(&s, " how are you?");
    cr_assert_str_eq(s.str, "Hello World, how are you?");
}

Test(append_c, test_append_c_null)
{
    string_t s;

    string_init(&s, "");
    s.str = NULL;
    s.append_c(&s, "World!");
    cr_assert_str_eq(s.str, "World!");
}

Test(append_s, test_append_s_null)
{
    string_t s;
    string_t ap;

    string_init(&s, "");
    string_init(&ap, "hey");
    s.str = NULL;
    s.append_s(&s, &ap);
    cr_assert_str_eq(s.str, "hey");
}

Test(append_s, test_append_s)
{
    string_t s;
    string_t ap;

    string_init(&s, "hey");
    string_init(&ap, "hey");
    s.append_s(&s, &ap);
    cr_assert_str_eq(s.str, "heyhey");
}


Test(at, test_at)
{
    string_t s;

    string_init(&s, "hey");
    cr_assert_eq(104, (int)s.at(&s, 0));
    cr_assert_eq(101, (int)s.at(&s, 1));
    cr_assert_eq(121, (int)s.at(&s, 2));
    cr_assert_eq(-1, (int)s.at(&s, 3));
    s.str = NULL;
    cr_assert_eq(-1, (int)s.at(&s, 3));
}

Test(clear, test_clear)
{
    string_t s;

    string_init(&s, "hey");
    s.clear(&s);
    cr_assert_null(s.append_c);
    cr_assert_null(s.append_s);
    cr_assert_null(s.assign_c);
    cr_assert_null(s.assign_s);
    cr_assert_null(s.at);
    cr_assert_null(s.clear);
    cr_assert_null(s.str);
}

Test(clear, test_clear_null)
{
    string_t s;

    clear(NULL);
}

Test(length, test_length)
{
    string_t s;

    string_init(&s, "hey");
    cr_assert_eq(3, s.length(&s));
}

Test(length, test_length_null)
{
    string_t s;

    string_init(&s, "NULL");
    string_destroy(&s);
    s.str = NULL;
    cr_assert_eq(-1, s.length(&s));
}

Test(compare_c, test_compare_c)
{
    string_t s;

    string_init(&s, "hey");
    cr_assert_eq(26, s.compare_c(&s, "Nope"));
}

Test(compare_c, test_compare_c_null)
{
    string_t s;

    string_init(&s, "hey");
    cr_assert_eq(-1, s.compare_c(&s, NULL));
    string_destroy(&s);
    s.str = NULL;
    cr_assert_eq(-1, s.compare_c(&s, "hey"));
}

Test(compare_s, test_compare_s)
{
    string_t s;
    string_t t;

    string_init(&s, "hey");
    string_init(&t, "Nope");
    cr_assert_eq(26, s.compare_s(&s, &t));
}
Test(copy, test_copy)
{
    string_t s;
    char *str = malloc(sizeof(char) * 3);

    string_init(&s, "hey");
    cr_assert_eq(4, s.copy(&s, &str[0], 3, 0));
    cr_assert_str_eq("hey", str);
}

Test(copy, test_copy_size_small)
{
    string_t s;
    char *str = malloc(sizeof(char) * 3);

    string_init(&s, "hey");
    cr_assert_eq(3, s.copy(&s, &str[0], 2, 1));
    cr_assert_str_eq("ey", str);
}

Test(c_str, test_c_str)
{
    string_t s;

    string_init(&s, "heylo");
    cr_assert_str_eq("heylo", s.c_str(&s));
}

Test(c_str, test_c_str_null)
{
    string_t s;

    string_init(&s, "Hey");
    cr_assert_eq(NULL, s.c_str(NULL));
}

Test(empty, test_empty)
{
    string_t s;

    string_init(&s, "heylo");
    cr_assert_eq(0, s.empty(&s));
    string_destroy(&s);
    s.str = NULL;
    cr_assert_eq(1, s.empty(&s));
}

Test(empty, test_empty_null)
{
    string_t s;

    string_init(&s, "Hey");
    cr_assert_eq(1, s.empty(NULL));
}

Test(find_s, test_find_s)
{
    string_t s;
    string_t t;
    int n = 0;

    string_init(&s, "Hello World!");
    string_init(&t, "Wo");
    n = s.find_s(&s, &t, 0);
    cr_assert_eq(n, 6);
    n = t.find_s(&t, &s, 0);
    cr_assert_eq(n, -1);
    n = t.find_s(&s, &t, 15);
    cr_assert_eq(n, -1);
}

Test(find_c, test_find_c)
{
    string_t s;
    int n = 0;

    string_init(&s, "Hello World!");
    n = s.find_c(&s, "Wo", 0);
    cr_assert_eq(n, 6);
    n = s.find_c(&s, "Hello World!s", 0);
    cr_assert_eq(n, -1);
    n = s.find_c(&s, "Wo", 15);
    cr_assert_eq(n, -1);
}

Test(insert_c, test_insert)
{
    string_t s;

    string_init(&s, "Naan");
    s.insert_c(&s, 2, "th");
    cr_assert_str_eq("Nathan", s.str);
}

Test(insert_c, test_insert_pos_high)
{
    string_t s;

    string_init(&s, "Naan");
    s.insert_c(&s, 7, "th");
    cr_assert_str_eq("Naanth", s.str);
}

Test(insert_c, test_to_int)
{
    string_t s;

    string_init(&s, "1234");
    cr_assert_eq(1234, s.to_int(&s));
}

Test(insert_c, test_to_int_neg)
{
    string_t s;

    string_init(&s, "-1234");
    cr_assert_eq(-1234, s.to_int(&s));
}

Test(insert_c, test_to_int_null)
{
    string_t s;

    string_init(&s, "1234");
    string_destroy(&s);
    s.str = NULL;
    cr_assert_eq(0, s.to_int(&s));
    cr_assert_eq(0, s.to_int(NULL));
}
