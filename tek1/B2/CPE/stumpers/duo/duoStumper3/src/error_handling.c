/*
** EPITECH PROJECT, 2021
** Duo-3
** File description:
** error_handling
*/

#include "error_handling.h"

int error_handling(int ac, char **av)
{
    if (ac != 4) {
        write(2, "Invalid arguments\n", strlen("Invalid arguments\n"));
        return (-1);
    }
    if (access(av[1], R_OK) == -1) {
        write(2, "The file can't be read\n", \
        strlen("The file can't be read\n"));
        return (-1);
    }
    if (strlen(av[2]) != 4) {
        write(2, "Invalid string\n", strlen("Invalid string\n"));
        return (-1);
    }
    for (int i = 0; av[3][i]; i++)
        if (av[3][i] < '0' || av[3][i] > '9') {
            write(2, "Invalid number of cycle\n", \
            strlen("Invalid number of cycle\n"));
            return (-1);
        }
    return (0);
}