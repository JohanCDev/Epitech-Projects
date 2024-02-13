/*
** EPITECH PROJECT, 2022
** Day04A
** File description:
** tests
*/

#include "../concat.h"
#include <stdlib.h>
#include <criterion/criterion.h>

void concat_strings(const char *str1, const char *str2, char **res);
void concat_struct(concat_t *str);

Test(concat_strings, test_concat_strings) {
    char *str = NULL;

    concat_strings("Hello", "World!", &str);
    cr_assert_str_eq(str, "HelloWorld!");
}

Test(concat_struct, test_concat_struct) {
    concat_t str = {.str1 = "Hey", .str2 = "Yo", .res = NULL};

    concat_struct(&str);
    cr_assert_str_eq(str.res, "HeyYo");
}
