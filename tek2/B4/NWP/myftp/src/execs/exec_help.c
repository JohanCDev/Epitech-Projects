/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** exec_help
*/

#include "server.h"
#include "client.h"
#include <my.h>

static void print_all_help(int fd)
{
    char *av_comm[14] = {"USER: Authenticate", "PASS: Enter password",
        "CWD: Change directory", "CDUP: Go to parent directory",
        "QUIT: Exit server", "DELE: Delete file", "PWD: Get current directory",
        "PASV", "PORT", "HELP: Print help", "NOOP: No operation",
        "RETR", "STOR", "LIST: List files"};

    dprintf(fd, "214-The following commands are recognized.\n");
    for (int i = 0; i < 14; i++)
        dprintf(fd, "%s\n", av_comm[i]);
    dprintf(fd, "214 Help OK.\n");
}

static bool check_help_value(char const *comm, char const *comm_to_check,
int fd)
{
    if (!strncmp(comm, comm_to_check, 3)) {
        dprintf(fd, "214 %s.\n", comm_to_check);
        return true;
    }
    return false;
}

static void print_part_help(int fd, const char **commands)
{
    bool found = false;
    char *av_comm[14] = {"USER: Authenticate", "PASS: Enter password",
        "CWD: Change directory", "CDUP: Go to parent directory",
        "QUIT: Exit server", "DELE: Delete file", "PWD: Get current directory",
        "PASV", "PORT", "HELP: Print help", "NOOP: No operation",
        "RETR", "STOR", "LIST: List files"};

    for (int i = 1; commands[i]; i++)
        for (int j = 0; j < 14; j++)
            check_help_value(commands[i], av_comm[j], fd) == true
            ? found = true : 0;
    if (found == false)
        dprintf(fd, "530 Command not found.\n");
}

int exec_help(client_t *cli, char const **command)
{
    if (cli->log != LOGGED_ST) {
        dprintf(cli->cli_fd, "530 Permission denied.\n");
        return 0;
    }
    if (get_arraylen(command) == 1)
        print_all_help(cli->cli_fd);
    else
        print_part_help(cli->cli_fd, command);
    return 0;
}
