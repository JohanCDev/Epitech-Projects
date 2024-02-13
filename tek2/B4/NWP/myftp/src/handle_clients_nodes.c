/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** handle_clients_nodes
*/

#include "my.h"
#include "client.h"
#include "server.h"

node_t *create_client_node(serv_t *serv, char const *path)
{
    client_t *client = malloc(sizeof(client_t));

    client->cli_fd = accept(serv->sock,
    (struct sockaddr *)&serv->cli, &serv->cli_len);
    if (client->cli_fd == -1) {
        perror("accept error");
        return NULL;
    }
    client->log = NO_ST;
    client->path = strdup(path);
    return new_node(client);
}

node_t *find_by_fd(int fd, linked_list_t *list)
{
    node_t *node = list->first;

    while (node) {
        if (((client_t *)node->data)->cli_fd == fd)
            return node;
        node = node->next;
    }
    return NULL;
}
