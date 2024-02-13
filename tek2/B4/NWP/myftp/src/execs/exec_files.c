/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** execs
*/

#include "server.h"
#include "client.h"
#include "my.h"
#include <sys/stat.h>

static bool has_rights(char const *path)
{
    struct stat st;

    if (stat(path, &st) == -1)
        return false;
    if (!access(path, X_OK))
        return true;
    else
        return false;
}

int exec_delete(client_t *cli, char const **command)
{
    if (cli->log != LOGGED_ST || get_arraylen(command) != 2) {
        dprintf(cli->cli_fd, "530 Permission denied.\n");
        return 0;
    } else if (has_rights(command[1]) && remove(command[1]) == 0) {
        dprintf(cli->cli_fd, "250 Requested file action okay, completed.\n");
        return 0;
    }
    dprintf(cli->cli_fd, "550 Failed to delete file.\n");
    return 0;
}

int exec_retr(client_t *cli, char const **command)
{
    (void)cli;
    (void)command;
    printf("exec RETR\n");
    return 0;
}

int exec_stor(client_t *cli, char const **command)
{
    (void)cli;
    (void)command;
    printf("exec STOR\n");
    return 0;
}
