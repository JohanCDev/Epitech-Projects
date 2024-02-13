/*
** EPITECH PROJECT, 2022
** Day05
** File description:
** clear
*/

#include "string.h"
#include <string.h>

void clear(string_t *this)
{
    int size = sizeof(string_t);
    if (this) {
        string_destroy(this);
        memset(this, 0, size);
    }
}
