/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** execs
*/

#include "server.h"
#include "client.h"

int exec_pasv(client_t *cli, char const **command)
{
    (void)cli;
    (void)command;
    printf("exec PASV\n");
    return 0;
}

int exec_port(client_t *cli, char const **command)
{
    (void)cli;
    (void)command;
    printf("exec PORT\n");
    return 0;
}
