/*
** EPITECH PROJECT, 2022
** Day05
** File description:
** at
*/

#include "string.h"
#include <string.h>

char at(const string_t *this, size_t pos)
{
    if (this->str == NULL || pos > strlen(this->str) - 1)
        return -1;
    return this->str[pos];
}
