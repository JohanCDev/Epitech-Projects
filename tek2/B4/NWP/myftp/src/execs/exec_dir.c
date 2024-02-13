/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** execs
*/

#include "server.h"
#include "client.h"
#include "my.h"
#include <dirent.h>

int exec_cwd(client_t *cli, char const **command)
{
    if (cli->log != LOGGED_ST || get_arraylen(command) != 2) {
        dprintf(cli->cli_fd, "550 Permission denied.\n");
        return 0;
    }
    chdir(cli->path);
    if (chdir(command[1]) == -1) {
        dprintf(cli->cli_fd, "550 Permission denied.\n");
        return 0;
    }
    cli->path = getcwd(NULL, 0);
    dprintf(cli->cli_fd, "250 Requested file action okay, completed.\n");
    return 0;
}

int exec_cdup(client_t *cli, char const **command)
{
    if (cli->log != LOGGED_ST || get_arraylen(command) != 1) {
        dprintf(cli->cli_fd, "530 Permission denied.\n");
        return 0;
    }
    chdir(cli->path);
    if (chdir("..") == -1) {
        dprintf(cli->cli_fd, "530 Permission denied.\n");
        return 0;
    }
    cli->path = getcwd(NULL, 0);
    dprintf(cli->cli_fd, "200 Command okay.\n");
    return 0;
}

int exec_pwd(client_t *cli, char const **command)
{
    if (cli->log != LOGGED_ST || get_arraylen(command) != 1) {
        dprintf(cli->cli_fd, "530 Permission denied.\n");
        return 0;
    }
    dprintf(cli->cli_fd, "257 \"%s\"\n", cli->path);
    return 0;
}

void list_dir(client_t *cli, char const *path)
{
    DIR *d;
    struct dirent *dir;

    chdir(cli->path);
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL)
            dprintf(cli->cli_fd, "%s\n", dir->d_name);
        closedir(d);
    } else {
        dprintf(cli->cli_fd, "550 Unexisting directory.\n");
    }
}

int exec_list(client_t *cli, char const **command)
{
    if (cli->log != LOGGED_ST || get_arraylen(command) > 2) {
        dprintf(cli->cli_fd, "550 Permission denied.\n");
        return 0;
    }
    list_dir(cli, command[1] == NULL ? "." : command[1]);
    return 0;
}
