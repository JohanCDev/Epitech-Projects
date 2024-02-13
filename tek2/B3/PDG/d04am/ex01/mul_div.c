/*
** EPITECH PROJECT, 2022
** Day04A
** File description:
** mul_div.c
*/

#include <unistd.h>
#include <stdio.h>

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    if (b == 0)
        *div = 42;
    else
        *div = a / b;
}

void mul_div_short(int *a, int *b)
{
    int tmp_a = *a;
    int tmp_b = *b;

    mul_div_long(tmp_a, tmp_b, a, b);
}
