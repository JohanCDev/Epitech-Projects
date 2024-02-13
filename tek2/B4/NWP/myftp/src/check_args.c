/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** check_args
*/

#include "server.h"
#include <stdio.h>
#include <string.h>

short unsigned int check_args(int argc, char const **argv)
{
    if (argc == 2 && !strcmp(argv[1], "-help")) {
        printf(HELPER_DISPLAY);
        return HELPER_DISPLAYED;
    } else if (argc == 3 && strspn(argv[1], "0123456789") == strlen(argv[1])
    && chdir(argv[2]) == 0) {
        return EXIT_SUCCESS;
    }
    fprintf(stderr, "Bad argument try with -help\n");
    return EXIT_FAILURE;
}