/*
** EPITECH PROJECT, 2022
** Day04P
** File description:
** modify
*/

#include "list.h"
#include <stdlib.h>

node_t *list_create_node(void *elem)
{
    node_t *node = malloc(sizeof(node_t));

    node->value = elem;
    node->next = NULL;
    return node;
}

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *node = list_create_node(elem);

    if (!node)
        return false;
    node->next = *front_ptr;
    *front_ptr = node;
    return true;
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    node_t *node = list_create_node(elem);
    list_t list = *front_ptr;

    if (!node)
        return false;
    if (!list)
        *front_ptr = node;
    else {
        list = *front_ptr;
        while (list->next) {
            list = list->next;
        }
        list->next = node;
    }
    return true;
}

bool iterate_list_add_position(int *pos, list_t *list)
{
    while (--(*pos)) {
        *list = (*list)->next;
        if (!list)
            return false;
    }
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
unsigned int position)
{
    node_t *node = list_create_node(elem);
    list_t list = *front_ptr;
    int i = 0;

    if (!node || position > list_get_size(list))
        return false;
    if (!list || position == 0)
        return list_add_elem_at_front(front_ptr, elem);
    else {
        list = *front_ptr;
        if (iterate_list_add_position(&position, &list) == false)
            return false;
        node->next = list->next;
        list->next = node;
    }
    return true;
}
