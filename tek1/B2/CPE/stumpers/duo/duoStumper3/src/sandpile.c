/*
** EPITECH PROJECT, 2021
** Duo-3
** File description:
** sandpile.c
*/
#include "sandpile.h"

void change_sandpile(map_t *map, int i)
{
    if (map->map[i - map->height])
        map->map[i - map->height] += 1;
    if (map->map[i + map->height])
        map->map[i + map->height] += 1;
    if ((i % map->width) + 1 < map->width && map->map[i + 1])
        map->map[i + 1] += 1;
    if ((i % map->width) - 1 >= 0 && map->map[i - 1])
        map->map[i - 1] += 1;
    map->map[i] -= 4;
}

void check_change_sandpile(map_t *map, int *i)
{
    if (map->map[*i] >= 4) {
        change_sandpile(map, *i);
        *i = 0;
    }
}

void check_if_nb_sup_four(map_t *map)
{
    for (int i = 0; i < map->height * map->width; i++) {
        check_change_sandpile(map, &i);
    }
}

int print_sandpile(map_t *map)
{
    int map_index = 0;
    
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            printf("%c", map->str[map->map[map_index]]);
            map_index++;
        }
        printf("\n");
    }
    return (0);
}

int sandpile(map_t *map, int nb_cycle)
{
    int i = 0;

    while (i < nb_cycle) {
        map->map[(map->height * map->width) / 2] += 1;
        check_if_nb_sup_four(map);
        i++;
    }
    return (print_sandpile(map));
}