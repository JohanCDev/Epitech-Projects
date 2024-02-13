/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** execs
*/

#include "server.h"
#include "client.h"
#include "my.h"

int exec_user(client_t *cli, char const **command)
{
    if (get_arraylen(command) != 2)
        dprintf(cli->cli_fd, "530 Permission denied.\n");
    else if (!strcmp(command[1], "Anonymous")) {
        dprintf(cli->cli_fd, "331 User name okay, need password.\n");
        cli->log = ANO_ST;
    } else {
        dprintf(cli->cli_fd, "331 User name okay, need password.\n");
        cli->log = USER_ST;
    }
    return 0;
}

int exec_pass(client_t *cli, char const **command)
{
    if (cli->log == NO_ST && get_arraylen(command) != 1) {
        dprintf(cli->cli_fd, "530 Permission denied.\n");
    } else if (cli->log == ANO_ST) {
        dprintf(cli->cli_fd, "230 User logged in, proceed.\n");
        cli->log = LOGGED_ST;
    } else
        dprintf(cli->cli_fd, "530 Permission denied.\n");
    return 0;
}

int exec_quit(client_t *cli, char const **command)
{
    if (get_arraylen(command) != 1 || cli->log != LOGGED_ST) {
        dprintf(cli->cli_fd, "530 Permission denied.\n");
        return 0;
    }
    dprintf(cli->cli_fd, "221 Service closing control connection.\n");
    cli->log = DISC_ST;
    return 0;
}

int exec_noop(client_t *cli, char const **command)
{
    if (get_arraylen(command) != 1 || cli->log != LOGGED_ST) {
        dprintf(cli->cli_fd, "530 Permission denied.\n");
        return 0;
    }
    dprintf(cli->cli_fd, "200 Command okay.\n");
    return 0;
}
