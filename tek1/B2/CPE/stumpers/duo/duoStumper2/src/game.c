/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper1-maxime3.vincent
** File description:
** game
*/

#include "my.h"
#include "game.h"

int check_x(int lines, int cols, game_t *game)
{
    int res = 0;

    if (lines > 0 && cols != 0 && game->map[lines - 1][cols] == 'X')
        res++;
    if (lines < game->height && game->map[lines + 1][cols] == 'X')
        res++;
    if (cols > 0 && game->map[lines][cols - 1] == 'X')
        res++;
    if (cols < game->width && game->map[lines][cols + 1] == 'X')
        res++;
    if (lines < game->height && cols < game->width && game->map[lines + 1][cols + 1] == 'X')
        res++;
    if (lines > 0 && cols > 0 && game->map[lines - 1][cols - 1] == 'X')
        res++;
    if (lines < game->height && cols > 0 && game->map[lines + 1][cols - 1] == 'X')
        res++;
    if (lines > 0 && cols < game->width && game->map[lines - 1][cols + 1] == 'X')
        res++;
    return (res);
}

void make_round(game_t *game)
{
    int y = 0;
    int x = 0;

    game->next_map = malloc(sizeof(char *) * 5);
    for (int i = 0; i < 5; i++)
        game->next_map[i] = malloc(sizeof(char) * 10);

    for (; game->map[y][0]; x++) {
        if (x == game->width - 1) {
            x = 0;
            y++;
            my_printf("\n");
        }
        my_printf("Hey char : %c\n", game->map[y][x]);
        if(check_x(y, x, game) == 3 || (check_x(y, x, game) == 2 && game->map[y][x] == 'X'))
            game->next_map[y][x] = 'X';
        if (check_x(y, x, game) < 2 || check_x(y, x, game) > 3)
            game->next_map[y][x] = '.';
    }
    my_printf("Out of for\n");
}

void play_game(game_t *game, int nb_rounds)
{
    for (int i = 0; i <= nb_rounds; i++) {
        make_round(game);
        my_printf("Hey\n");
        game->map = copy_array(game->next_map, 1, game->height);
        my_printf("Hey2\n");
        array_free(game->next_map);
    }
}