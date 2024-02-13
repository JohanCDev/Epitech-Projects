/*
** EPITECH PROJECT, 2022
** Day04P
** File description:
** modify
*/

#include "int_list.h"
#include <stdlib.h>

int_node_t *int_list_create_node(int elem)
{
    int_node_t *node = malloc(sizeof(int_node_t));

    node->value = elem;
    node->next = NULL;
    return node;
}

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_node_t *node = int_list_create_node(elem);

    if (!node)
        return false;
    node->next = *front_ptr;
    *front_ptr = node;
    return true;
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_node_t *node = int_list_create_node(elem);
    int_list_t list = *front_ptr;

    if (!node)
        return false;
    else if (!list)
        *front_ptr = node;
    list = *front_ptr;
    while (list->next)
        list = list->next;
    list->next = node;
    return true;
}

bool iterate_int_list_add_position(unsigned int *pos, int_list_t *list)
{
    while (--(*pos)) {
        *list = (*list)->next;
        if (!list)
            return false;
    }
    return true;
}

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem,
unsigned int position)
{
    int_node_t *node = int_list_create_node(elem);
    int_list_t list = *front_ptr;

    if (!node || position > int_list_get_size(list))
        return false;
    else if (!list || position == 0)
        return int_list_add_elem_at_front(front_ptr, elem);
    list = *front_ptr;
    if (iterate_int_list_add_position(&position, &list) == false)
        return false;
    node->next = list->next;
    list->next = node;
    return true;
}
