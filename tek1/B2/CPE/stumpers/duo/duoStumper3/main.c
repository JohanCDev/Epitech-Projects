/*
** EPITECH PROJECT, 2021
** main
** File description:
** for stumper 3
*/

#include "error_handling.h"
#include "get_map.h"
#include "sandpile.h"

int main(int ac, char **av)
{
    map_t map = {0, 0, NULL, 0, NULL};
    int nb_cycle;

    if (error_handling(ac, av) == -1)
        return (84);
    nb_cycle = atoi(av[3]);
    map = get_map(av[1], av[2]);
    if (map.ret == 84)
        return (84);
    if (sandpile(&map, nb_cycle) == -1)
        return (84);
    free(map.map);
    free(map.str);
    return (0);
}
