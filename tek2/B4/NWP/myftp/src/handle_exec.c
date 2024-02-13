/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** handle_exec
*/

#include "execution.h"
#include <stdio.h>

int handle_execution_return(int found, int fd)
{
    switch (found) {
    case COMMAND_FOUND:
        return 0;
    case COMMAND_NOT_FOUND:
        dprintf(fd, "500 Syntax error, command unrecognized.\n");
        return 0;
    case COMMAND_QUIT:
        return 1;
    }
    return 0;
}
