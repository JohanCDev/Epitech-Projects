/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** main
*/

#include <stdio.h>
#include "server.h"

short unsigned int check_args(int argc, char const **argv);

int main(int argc, char const **argv)
{
    switch (check_args(argc, argv)) {
    case EXIT_SUCCESS:
        return process(atoi(argv[1]), argv[2]);
    case HELPER_DISPLAYED:
        return EXIT_SUCCESS;
    default:
        return FAILURE_PROGRAM;
    }
    return FAILURE_PROGRAM;
}
