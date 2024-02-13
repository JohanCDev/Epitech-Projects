/*
** EPITECH PROJECT, 2022
** Day05
** File description:
** find
*/

#include "string.h"
#include <string.h>

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if ((int)pos >= this->length(this) || this->length(this) < str->length(str))
        return -1;
    return ((strstr(&this->str[pos], str->str)) - (this->str));
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    if ((int)pos >= this->length(this) || this->length(this) < (int)strlen(str))
        return -1;
    return ((strstr(&this->str[pos], str)) - (this->str));
}
