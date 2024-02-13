/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper6-johan.chrillesen
** File description:
** play_game
*/

#include "tictactoe.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

typedef struct inputs_s {
    int col;
    int line;
} inputs_t;

int get_inputs(inputs_t *inputs, char *str, tic_t *tic)
{
    int start_sec_nb = 0;

    for (start_sec_nb = 0; str[start_sec_nb] != ',' && str[start_sec_nb]; \
    start_sec_nb++);
    if (my_str_isfloat(str) == 0)
        return (-1);
    inputs->col = atoi(str);
    inputs->line = atoi(&str[start_sec_nb + 1]);
    if (inputs->line >= tic->size || inputs->col >= tic->size)
        return (-1);
    if (tic->map[inputs->line * tic->size + inputs->col] != 0)
        return (-1);
    return (0);
}

int one_turn(tic_t *tic, int player)
{
    char *str = NULL;
    size_t len = 0;
    ssize_t read = 0;
    inputs_t inputs = {0, 0};

    my_put_player(player);
    if ((read = getline(&str, &len, stdin)) == -1)
        if (str) {
            free(str);
            str = NULL;
            return (-1);
        }
    str[read] = 0;
    if (get_inputs(&inputs, str, tic) == -1)
        if (str) {
            free(str);
            str = NULL;
            return (0);
        }
    tic->map[inputs.line * tic->size + inputs.col] = player;
    return (1);
}

int player_turn(tic_t *tic, int player)
{
    int ret = 0;

    do {
        ret = one_turn(tic, player);
        if (ret == -1)
            return (-1);
    } while (ret != 1);
    return (0);
}

bool map_is_full(tic_t *tic)
{
    for (int i = 0; i < tic->size * tic->size; i++) {
        if (tic->map[i] == 0)
            return (false);
    }
    return (true);
}

int play_game(tic_t *tic)
{
    print_map(tic, 0);
    while (!map_is_full(tic)) {
        if (player_turn(tic, 1) == -1)
            return (-1);
        print_map(tic, 1);
        if (check_victory(tic, 1))
            return (0);
        if (map_is_full(tic))
            break;
        if (player_turn(tic, 2) == -1)
            return (-1);
        print_map(tic, 1);
        if (check_victory(tic, 2))
            return (0);
    }
    write(1, DRAW, strlen(DRAW));
    return (0);
}