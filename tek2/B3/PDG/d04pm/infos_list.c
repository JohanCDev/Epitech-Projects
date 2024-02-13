/*
** EPITECH PROJECT, 2022
** Day04P
** File description:
** infos
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int list_get_size(list_t list)
{
    unsigned int size = 0;

    while (list != NULL) {
        size++;
        list = list->next;
    }
    return size;
}

bool list_is_empty(list_t list)
{
    return list == NULL;
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    while (list != NULL) {
        val_disp(list->value);
        list = list->next;
    }
}
