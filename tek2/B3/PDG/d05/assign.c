/*
** EPITECH PROJECT, 2022
** Day05
** File description:
** assign
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    string_destroy(this);
    string_init(this, str->str);
}

void assign_c(string_t *this, const char *s)
{
    string_destroy(this);
    string_init(this, s);
}
