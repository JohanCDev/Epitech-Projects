/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** main_loop
*/

#include "server.h"
#include "client.h"
#include "execution.h"
#include "my.h"

static int execute_single_command(client_t *cli,
char const **com, int i)
{
    int (*func[14])(client_t * cli, char const **com) = {
        &exec_user, &exec_pass, &exec_cwd, &exec_cdup, &exec_quit, &exec_delete,
        &exec_pwd, &exec_pasv, &exec_port, &exec_help, &exec_noop, &exec_retr,
        &exec_stor, &exec_list};
    return (*func[i])(cli, com);
}

static int check_quit(client_t *cli, char const **command, int i)
{
    char *cmds[14] = {"USER", "PASS", "CWD", "CDUP", "QUIT", "DELE", "PWD",
        "PASV", "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST"};

    if (!strcmp(cmds[i], command[0])) {
        if (execute_single_command(cli, command, i) == 1)
            return COMMAND_QUIT;
        return COMMAND_FOUND;
    }
    return COMMAND_NOT_FOUND;
}

static int do_command(client_t *cli, char const *line)
{
    char **command = my_str_to_word_array(line, " \n\r\t");
    int found = COMMAND_NOT_FOUND;
    int found_tmp = found;

    if (command == NULL)
        return my_put_error(STWA_ERR_MESS, -1, stderr);
    if (command[0] == NULL) {
        free(command);
        return handle_execution_return(found, cli->cli_fd);
    }
    for (int i = 0; i < 14; i++) {
        found_tmp = check_quit(cli, (char const **)command, i);
        found != COMMAND_FOUND && found != COMMAND_QUIT ? found = found_tmp : 0;
    }
    return handle_execution_return(found, cli->cli_fd);
}

int execute(client_t *cli)
{
    char *line = NULL;
    size_t len = 0;

    printf("Waiting for command...\n");
    if (getline(&line, &len, fdopen(cli->cli_fd, "ra")) < 0)
        return -1;
    if (do_command(cli, line) == -1 || cli->log == DISC_ST)
        return -1;
    memset(line, 0, sizeof(char) * strlen(line));
    return 0;
}
