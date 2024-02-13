/*
** EPITECH PROJECT, 2022
** Day05
** File description:
** to_int
*/

#include <stdlib.h>
#include "string.h"

int to_int(const string_t *this)
{
    if (this && this->str)
        return atoi(this->str);
    return 0;
}