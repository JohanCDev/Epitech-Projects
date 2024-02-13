/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** victory
*/

#include "tictactoe.h"
#include <string.h>
#include <unistd.h>

bool check_this_col(tic_t *tic, int i, int turn)
{
    for (int j = 0; j < tic->size; j++) {
        if (tic->map[tic->size * j + i] != turn)
            return (false);
    }
    return (true);
}

bool check_this_line(tic_t *tic, int i, int turn)
{
    for (int j = 0; j < tic->size; j++) {
        if (tic->map[tic->size * i + j] != turn)
            return (false);
    }
    return (true);
}

bool check_diagonals(tic_t *tic, int turn)
{
    bool result_one = true;
    bool result_two = true;

    for (int i = 0; i < tic->size && result_one; i++) {
        if (tic->map[tic->size * i + i] != turn)
            result_one = false;
    }
    for (int i = 1; i <= tic->size && result_two; i++) {
        if (tic->map[(tic->size - 1) * i] != turn)
            result_two = false;
    }
    if (result_one || result_two)
        return (true);
    return (false);
}

void print_victory(int turn)
{
    if (turn == 1)
        write(1, P_ONE_VICTORY, strlen(P_ONE_VICTORY));
    else
        write(1, P_TWO_VICTORY, strlen(P_TWO_VICTORY));
}

bool check_victory(tic_t *tic, int turn)
{
    for (int i = 0; i < tic->size; i++)
        if (check_this_col(tic, i, turn)) {
            print_victory(turn);
            return (true);
        }
    for (int i = 0; i < tic->size; i++)
        if (check_this_line(tic, i, turn)) {
            print_victory(turn);
            return (true);
        }
    if (check_diagonals(tic, turn)) {
        print_victory(turn);
        return (true);
    }
    return (false);
}