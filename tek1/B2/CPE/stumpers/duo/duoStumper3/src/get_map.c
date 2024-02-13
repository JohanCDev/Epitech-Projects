/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper3-johan.chrillesen
** File description:
** get_map
*/

#include "get_map.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "sandpile.h"

void change_value(map_t *map, const char *buff, int i, int *int_index)
{
    for (int j = 0; map->str[j]; j++) {
        if (buff[i] == map->str[j]) {
            map->map[*int_index] = j;
            *int_index += 1;
        }
    }
}

map_t fill_map(map_t map, char const *buff, int size)
{
    int int_index = 0;

    map.map = calloc(sizeof(int), size);
    if (map.map == NULL) {
        map.ret = 84;
        return (map);
    }
    for (int i = 0; i < buff[i]; i++) {
        change_value(&map, buff, i, &int_index);
    }
    return (map);
}

int check_length(char const *buffer, int i, int nb_columns, \
int nb_columns_base)
{
    if (buffer[i] == '\n') {
        if (nb_columns != nb_columns_base)
            return (-1);
        nb_columns = 0;
    }
    return (nb_columns);
}

map_t check_map(map_t map, int size, int fd)
{
    char *buff = malloc(sizeof(char) * (size + 1));

    if (buff == NULL) {
        map.ret = 84;
        free(buff);
        return (map);
    }
    read(fd, buff, size + 1);
    buff[size] = '\0';
    map.height = get_height(buff);
    map.width = get_length(buff, map.height);
    if (map.height != map.width) {
        map.ret = 84;
        free(buff);
        return (map);
    }
    map = fill_map(map, buff, size);
    return (map);
}

map_t get_map(char const *filepath, char const *characters)
{
    map_t map = {0, 0, 0, 0, NULL};
    struct stat file_stat;
    int fd = open(filepath, O_RDONLY);

    map.str = strdup(characters);
    if (fd == -1 || stat(filepath, &file_stat)) {
        close(fd);
        map.ret = 84;
        return (map);
    } else
        map = check_map(map, (int)file_stat.st_size, fd);
    if (map.ret == 84)
        close(fd);
    return (map);
}