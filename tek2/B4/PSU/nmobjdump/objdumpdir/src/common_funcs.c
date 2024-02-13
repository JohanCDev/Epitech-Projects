/*
** EPITECH PROJECT, 2022
** nmobjdump
** File description:
** common_funcs
*/

#include <elf.h>
#include "objdump.h"
#include "my.h"
#include <string.h>

void show_value_char(void *data, uint32_t size)
{
    char *str = NULL;

    printf(" ");
    for (uint32_t i = 0; i < size; i++) {
        str = data + i;
        if (check_char_valid(*str) == 1)
            printf("%c", *str);
        else
            printf(".");
    }
}

void print_spaces(int i)
{
    for (uint32_t c = i % 16; c < 16; c++) {
        if (c % 4 == 0)
            printf("   ");
        else
            printf("  ");
    }
}

int	check_char_valid(char c)
{
    if (c >= 32 && c <= 126)
        return 1;
    return 0;
}
