/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** main_loop
*/

#include "server.h"
#include "client.h"

int loop_server(serv_t *serv, char const *path)
{
    serv->read_sock = serv->curr_sock;
    if (select(FD_SETSIZE, &serv->read_sock, NULL, NULL, NULL) < 0) {
        perror("select error");
        return -1;
    }
    for (int i = 0; i < FD_SETSIZE; i++)
        if (handle_select(serv, i, path) == -1)
            return -1;
    return 0;
}
