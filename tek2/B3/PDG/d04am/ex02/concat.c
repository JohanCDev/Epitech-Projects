/*
** EPITECH PROJECT, 2022
** Day04A
** File description:
** mul_div.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "concat.h"

void concat_strings(const char *str1, const char *str2, char **res)
{
    *res = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    if (*res == NULL)
        return;
    *res = strcat(strcpy(*res, str1), str2);
}

void concat_struct(concat_t *str)
{
    concat_strings(str->str1, str->str2, &str->res);
}
