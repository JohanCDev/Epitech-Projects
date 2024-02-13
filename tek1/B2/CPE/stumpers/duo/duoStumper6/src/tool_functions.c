/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** tool_functions
*/

#include "tictactoe.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

bool str_is_num(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return (false);
        }
    }
    return (true);
}

bool my_str_isfloat(char const *str)
{
    int is_okay = 0;
    int i = 0;
    bool float_found = 0;

    for (; str[i] != 0; i++) {
        if ((str[i] >= 48 && str[i] <= 57) || str[i] == '\n')
            is_okay = 1;
        else if (str[i] == ',' && float_found == 0) {
            is_okay = 1;
            float_found = 1;
        } else
            return (0);
    }
    if (float_found != 1)
        return (0);
    return (is_okay);
}

bool is_a_valid_character(char c)
{
    if (c <= 32 || c > 126)
        return (false);
    if (c == '+' || c == '-' || c == '|')
        return (false);
    return (true);
}

void my_free_string(char *str)
{
    if (str) {
        free(str);
        str = NULL;
    }
}

void my_put_player(int player)
{
    write(1, "Player ", strlen("Player "));
    if (player == 1)
        write(1, "1", strlen("1"));
    else
        write(1, "2", strlen("2"));
    write(1, "> ", strlen("> "));
}