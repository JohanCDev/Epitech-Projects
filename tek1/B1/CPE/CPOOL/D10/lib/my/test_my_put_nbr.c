/*
** EPITECH PROJECT, 2020
** test
** File description:
** my_put_nbr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_put_nbr(int nb);

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(my_put_nbr, test, .init = redirect_all_stdout)
{
    my_put_nbr(1);
    cr_assert_stdout_eq_str("1");
}

Test(my_put_nbr, test1, .init = redirect_all_stdout)
{
    my_put_nbr(12);
    cr_assert_stdout_eq_str("12");
}

Test(my_put_nbr, test2, .init = redirect_all_stdout)
{
    my_put_nbr(-1);
    cr_assert_stdout_eq_str("-1");
}

Test(my_put_nbr, test3, .init = redirect_all_stdout)
{
    my_put_nbr(-12);
    cr_assert_stdout_eq_str("-12");
}