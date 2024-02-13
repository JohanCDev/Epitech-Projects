/*
** EPITECH PROJECT, 2022
** Day05
** File description:
** insert
*/

#include "string.h"
#include <string.h>
#include <stdlib.h>

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *fin_str = NULL;
    size_t i = 0;

    if ((int)pos > this->length(this))
        append_c(this, str);
    else {
        fin_str = malloc(sizeof(char) * (strlen(str) + this->length(this) + 1));
        strncpy(fin_str, this->str, pos);
        for (; str[i]; i++)
            fin_str[i + pos] = str[i];
        fin_str[i + pos] = '\0';
        strcat(fin_str, &this->str[pos]);
        assign_c(this, fin_str);
        free(fin_str);
    }
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    insert_c(this, pos, str->str);
}
