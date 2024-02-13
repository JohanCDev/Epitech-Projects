/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper6-johan.chrillesen
** File description:
** print_map
*/

#include "tictactoe.h"
#include <unistd.h>

void print_horizontal_line(int size)
{
    write(1, "+", 1);
    for (int i = 0; i < size; i++)
        write(1, "-", 1);
    write(1, "+\n", 2);
}

void switch_char_to_print(tic_t *tic, int i)
{
    if (tic->map[i] == 0)
        write(1, " ", 1);
    if (tic->map[i] == 1)
        write(1, &tic->p_one, 1);
    if (tic->map[i] == 2)
        write(1, &tic->p_two, 1);
}

void print_map(tic_t *tic, int jump)
{
    if (isatty(1) == 1)
        if (jump == 1)
            write(1, "\n", 1);
    print_horizontal_line(tic->size);
    for (int i = 0; i < tic->size * tic->size; i++) {
        if (i % tic->size == 0)
            write(1, "|", 1);
        switch_char_to_print(tic, i);
        if ((i + 1) % tic->size == 0)
            write(1, "|\n", 2);
    }
    print_horizontal_line(tic->size);
    if (isatty(1))
        write(1, "\n", 1);
}