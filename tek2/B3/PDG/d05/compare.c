/*
** EPITECH PROJECT, 2022
** Day05
** File description:
** compare
*/

#include "string.h"
#include <string.h>

int compare_s(const string_t *this, const string_t *str)
{
    if (this->str == NULL || str->str == NULL)
        return -1;
    return strcmp(this->str, str->str);
}

int compare_c(const string_t *this, const char *str)
{
    if (this->str == NULL || str == NULL)
        return -1;
    return strcmp(this->str, str);
}
