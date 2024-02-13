/*
** EPITECH PROJECT, 2021
** B-SYN-200-NAN-2-1-palindrome-johan.chrillesen
** File description:
** test_helpers
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "pal.h"
#include "my.h"

void redirect_all_std(void);

Test(ipal_tindrom, test_ipal_tindromindrome)
{
    char *nb1 = my_strdup("12521");
    char *nb2 = my_strdup("1459541");
    char *nb3 = my_strdup("2565");
    char *nb4 = my_strdup("12521");
    int inb1 = ipal_tindrom(nb1);
    int inb2 = ipal_tindrom(nb2);
    int inb3 = ipal_tindrom(nb3);
    int inb4 = ipal_tindrom(nb4);

    cr_assert_eq(inb1, 1);
    cr_assert_eq(inb2, 1);
    cr_assert_eq(inb3, 0);
    cr_assert_eq(inb4, 1);
}

Test(ipal_tindrom, test_ipal_tindrom_next)
{
    char *nb5 = my_strdup("5");
    char *nb6 = my_strdup("55");
    char *nb7 = my_strdup("54");
    int inb5 = ipal_tindrom(nb5);
    int inb6 = ipal_tindrom(nb6);
    int inb7 = ipal_tindrom(nb7);

    cr_assert_eq(inb5, 1);
    cr_assert_eq(inb6, 1);
    cr_assert_eq(inb7, 0);
}

Test(test_printing, print_result, .init = redirect_all_std)
{
    print_result(3, "151", 5, 6);

    cr_assert_stdout_eq_str("3 leads to 151 in 5 iteration(s) in base 6\n");
}

Test(get_new_number, test_get_new_number)
{
    char *res1 = get_new_number("150");
    char *res2 = get_new_number("151");

    cr_assert_str_eq(res1, "201");
    cr_assert_str_eq(res2, "302");
}