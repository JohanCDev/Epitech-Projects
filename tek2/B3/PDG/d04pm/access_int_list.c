/*
** EPITECH PROJECT, 2022
** Day04P
** File description:
** get
*/

#include "int_list.h"
#include <stdlib.h>

int int_list_get_elem_at_front(int_list_t list)
{
    if (list == NULL)
        return 0;
    return list->value;
}

int int_list_get_elem_at_back(int_list_t list)
{
    if (list == NULL)
        return 0;
    while (list->next)
        list = list->next;
    return list->value;
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    if (!list || position > int_list_get_size(list))
        return 0;
    else if (position == 0)
        return int_list_get_elem_at_front(list);
    while (--position)
        list = list->next;
    return list->value;
}
