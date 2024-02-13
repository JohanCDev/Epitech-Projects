/*
** EPITECH PROJECT, 2022
** Day04P
** File description:
** infos
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int int_list_get_size(int_list_t list)
{
    unsigned int size = 0;
    while (list->next != NULL) {
        size++;
        list = list->next;
    }
    return size;
}

bool int_list_is_empty(int_list_t list)
{
    return list == NULL;
}

void int_list_dump(int_list_t list)
{
    if (list == NULL)
        return;
    while (list != NULL) {
        printf("%d\n", list->value);
        list = list->next;
    }
}
