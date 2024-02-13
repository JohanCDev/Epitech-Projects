/*
** EPITECH PROJECT, 2022
** nmobjdump
** File description:
** main
*/

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my.h"
#include "objdump.h"

int main(int argc, char **argv)
{
    switch (argc) {
    case 1:
        return (process_single("a.out") == false ? 0 : 84);
    case 2:
        return (process_single(argv[1]) == false ? 0 : 84);
    default:
        return (process_all(&argv[1]) == false ? 0 : 84);
    }
    return 0;
}
