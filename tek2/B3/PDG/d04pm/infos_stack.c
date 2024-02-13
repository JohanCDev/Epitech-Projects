/*
** EPITECH PROJECT, 2022
** Day04P
** File description:
** infos_stack
*/

#include "stack.h"
#include <stdlib.h>

unsigned int stack_get_size(stack_t stack)
{
    unsigned int size = 0;
    while (stack != NULL)
        size++;
    return size;
}

bool stack_is_empty(stack_t stack)
{
    if (stack)
        return true;
    return false;
}
