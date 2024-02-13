/*
** EPITECH PROJECT, 2022
** Day04A
** File description:
** print
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print.h"

void print_normal(const char *str)
{
    puts(str);
}

void print_reverse(const char *str)
{
    char *tmp = strdup(str);
    int i;
    int size = 0;
    char stock;

    while (tmp[size] != '\0') {
        size++;
    }
    size--;
    for (i = 0; i <= size; i++) {
        stock = tmp[i];
        tmp[i] = tmp[size];
        tmp[size] = stock;
        size--;
    }
    puts((const char *)tmp);
    free(tmp);
}

void print_upper(const char *str)
{
    char *tmp = strdup(str);
    int i = 0;
    while (tmp[i] != 0) {
        if (tmp[i] >= 97 && tmp[i] <= 122)
            tmp[i] -= 32;
        i++;
    }
    puts((const char *)tmp);
    free(tmp);
}

void print_42(const char *str)
{
    (void)str;
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void(*type_of_print[])(const char *) = {&print_normal,
        &print_reverse, &print_upper, &print_42};
    type_of_print[action](str);
}
