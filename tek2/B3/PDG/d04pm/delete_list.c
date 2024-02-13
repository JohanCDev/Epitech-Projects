/*
** EPITECH PROJECT, 2022
** Day04P
** File description:
** delete
*/

#include "list.h"
#include <stdlib.h>

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t list = *front_ptr;

    if (!list)
        return false;
    *front_ptr = list->next;
    free(list);
    return true;
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t list = *front_ptr;
    list_t prev;

    if (!list)
        return (false);
    while (list->next) {
        prev = list;
        list = list->next;
    }
    if (prev)
        prev->next = NULL;
    else
        *front_ptr = NULL;
    free(list);
    return true;
}

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t prev = *front_ptr;
    list_t list;

    if (position == 0)
        return list_del_elem_at_front(front_ptr);
    else if (!front_ptr)
        return (false);
    list = prev->next;
    while (--position) {
        if (!list)
            return (false);
        prev = list;
        list = list->next;
    }
    if (list)
        prev->next = list->next;
    free(list);
    return true;
}

void list_clear(list_t *front_ptr)
{
    while ((*front_ptr)->next != NULL)
        list_del_elem_at_back(front_ptr);
    free(*front_ptr);
    *front_ptr = NULL;
}
