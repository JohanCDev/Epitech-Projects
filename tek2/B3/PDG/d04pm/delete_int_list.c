/*
** EPITECH PROJECT, 2022
** Day04P
** File description:
** delete
*/

#include "int_list.h"
#include <stdlib.h>

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    int_list_t list = *front_ptr;

    if (!list)
        return (false);
    *front_ptr = list->next;
    free(list);
    return (true);
}

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_list_t list = *front_ptr;
    int_list_t prev;

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
    if (list) {
        free(list);
        list = NULL;
    }
    return (true);
}

bool int_list_del_elem_at_position(int_list_t *front_ptr, unsigned int position)
{
    int_list_t prev = *front_ptr;
    int_list_t list;

    if (position == 0)
        return int_list_del_elem_at_front(front_ptr);
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
    if (list) {
        free(list);
        list = NULL;
    }
    return (true);
}

void int_list_clear(int_list_t *front_ptr)
{
    while ((*front_ptr)->next != NULL)
        int_list_del_elem_at_back(front_ptr);
    if (*front_ptr) {
        free(*front_ptr);
        *front_ptr = NULL;
    }
}
