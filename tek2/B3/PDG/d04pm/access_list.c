/*
** EPITECH PROJECT, 2022
** Day04P
** File description:
** get
*/

#include "list.h"
#include <stdlib.h>

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return 0;
    return list->value;
}

void *list_get_elem_at_back(list_t list)
{
    if (list == NULL)
        return 0;
    while (list->next)
        list = list->next;
    return list->value;
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    position++;
    if (!list || position > list_get_size(list))
        return (void *)(-1);
    else if (position == 0)
        return list_get_elem_at_front(list);
    while (--position)
        list = list->next;
    return list->value;
}