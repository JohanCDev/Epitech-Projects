/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** process
*/

#include <signal.h>
#include <stdbool.h>
#include <string.h>
#include "client.h"
#include "execution.h"
#include "server.h"
#include "my.h"
#include "linked_list.h"

int exit_program(serv_t *serv, int exit_status)
{
    close(serv->sock);
    return exit_status;
}

int initialize_server_struct(serv_t *serv, int port)
{
    int list = 0;

    serv->sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv->sock == -1)
        return -1;
    serv->serv.sin_family = AF_INET;
    serv->serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv->serv.sin_port = htons(port);
    bind(serv->sock, (struct sockaddr *)&serv->serv, sizeof(serv->serv));
    list = listen(serv->sock, 5);
    if (list != 0) {
        printf("Listen failed...%d\n", list);
        close(serv->sock);
        return -1;
    }
    serv->cli_len = sizeof(serv->cli);
    return 0;
}

int process(int port, char const *path)
{
    serv_t serv;

    serv.list = new_linked_list();
    initialize_server_struct(&serv, port);
    FD_ZERO(&serv.curr_sock);
    FD_SET(serv.sock, &serv.curr_sock);
    while (1)
        if (loop_server(&serv, path) == 1)
            break;
    return exit_program(&serv, EXIT_SUCCESS);
}
