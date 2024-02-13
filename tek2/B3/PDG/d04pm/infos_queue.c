/*
** EPITECH PROJECT, 2022
** Day04P
** File description:
** infos
*/

#include "queue.h"
#include <stdlib.h>

unsigned int queue_get_size(queue_t queue)
{
    unsigned int size = 0;
    while (queue != NULL)
        size++;
    return size;
}

bool queue_is_empty(queue_t queue)
{
    if (queue)
        return true;
    return false;
}
