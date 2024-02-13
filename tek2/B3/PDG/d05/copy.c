/*
** EPITECH PROJECT, 2022
** Day05
** File description:
** copy
*/

#include "string.h"
#include <string.h>
#include <stdlib.h>

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = 0;

    if (this->str && s) {
        while (n-- && pos < strlen(this->str))
            s[i++] = this->str[pos++];
    }
    return i + 1;
}
