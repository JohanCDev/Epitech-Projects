/*
** EPITECH PROJECT, 2022
** Day04A
** File description:
** mul_div.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "concat.h"

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    *res = malloc(sizeof(size_t) * (height + 1));
    if (res == NULL)
        return;
    for (int i = 0; i < height; i++) {
        (*res)[i] = malloc(sizeof(size_t) * (width + 1));
        for (int j = 0; j < width; j++) {
            (*res)[i][j] = array[(width * i + j)];
        }
    }
}

void array_2d_free(int **array, size_t height, size_t width)
{
    (void) width;
    for (int i = 0; i < height; i++)
        free(array[i]);
    free(array);
}
