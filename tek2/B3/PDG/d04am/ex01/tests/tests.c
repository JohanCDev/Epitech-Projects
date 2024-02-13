/*
** EPITECH PROJECT, 2022
** Day04A
** File description:
** tests
*/

#include <criterion/criterion.h>

void mul_div_short(int *a, int *b);
void mul_div_long(int a, int b, int *mul, int *div);

Test(mul_div_long, test_mul_div_long) {
    int mul = 0;
    int div = 0;

    mul_div_long(42, 3, &mul, &div);
    cr_assert_eq(mul, 126);
    cr_assert_eq(div, 14);
    mul_div_long(21, 0, &mul, &div);
    cr_assert_eq(mul, 0);
    cr_assert_eq(div, 42);
}

Test(mul_div_short, test_mul_div_short) {
    int mul = 20;
    int div = 2;

    mul_div_short(&mul, &div);
    cr_assert_eq(mul, 40);
    cr_assert_eq(div, 10);
    div = 0;
    mul_div_short(&mul, &div);
    cr_assert_eq(mul, 0);
    cr_assert_eq(div, 42);
}
