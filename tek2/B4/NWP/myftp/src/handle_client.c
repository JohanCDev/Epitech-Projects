/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** handle_client
*/

#include "server.h"
#include "client.h"

static int handle_new_client(serv_t *serv, char const *path)
{
    node_t *new_client = create_client_node(serv, path);
    client_t *tmp = NULL;

    if (new_client == NULL)
        return -1;
    insert_last_in_list(new_client, serv->list);
    printf("Connection from %s:%hu\n", inet_ntoa(serv->cli.sin_addr),
    ntohs(serv->cli.sin_port));
    tmp = (client_t *)new_client->data;
    dprintf(tmp->cli_fd, "220 Service ready for new user.\n");
    FD_SET(tmp->cli_fd, &serv->curr_sock);
    return 0;
}

static void handle_client(int i, serv_t *serv)
{
    client_t *client = (client_t *)(find_by_fd(i, serv->list))->data;

    if (execute(client) == -1 || client->log == DISC_ST) {
        close(client->cli_fd);
        FD_CLR(client->cli_fd, &serv->curr_sock);
    }
}

static int helper_client_handler(int i, serv_t *serv, char const *path)
{
    if (i == serv->sock) {
        if (handle_new_client(serv, path) == -1)
            return -1;
        return 1;
    }
    return 0;
}

int handle_select(serv_t *serv, int i, char const *path)
{
    int ret = 0;

    if (FD_ISSET(i, &serv->read_sock)) {
        ret = helper_client_handler(i, serv, path);
        if (ret == -1) {
            return -1;
        } else if (ret == 0) {
            handle_client(i, serv);
        }
    }
    return 0;
}
