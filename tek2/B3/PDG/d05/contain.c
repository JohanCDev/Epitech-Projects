/*
** EPITECH PROJECT, 2022
** Day05
** File description:
** contain
*/

#include <string.h>
#include "string.h"

const char *c_str(const string_t *this)
{
    if (this)
        return this->str;
    return NULL;
}
