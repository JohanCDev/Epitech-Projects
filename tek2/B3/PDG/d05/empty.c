/*
** EPITECH PROJECT, 2022
** Day05
** File description:
** empty
*/

#include "string.h"
#include <string.h>

int empty(const string_t *this)
{
    if (this == NULL)
        return 1;
    else if (this->str)
        return 0;
    return 1;
}
