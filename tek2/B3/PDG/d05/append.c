/*
** EPITECH PROJECT, 2022
** Day05
** File description:
** append
*/

#include "string.h"
#include <string.h>
#include <stdlib.h>

void append_s(string_t *this, const string_t *ap)
{
    char *fin_res = NULL;

    if (this->str == NULL)
        this->assign_s(this, ap);
    else {
        fin_res = malloc(sizeof(char) * (strlen(this->str) \
        + strlen(ap->str) + 1));
        if (fin_res == NULL)
            return;
        strcpy(fin_res, this->str);
        strcpy(&fin_res[strlen(this->str)], ap->str);
        string_destroy(this);
        this->str = strdup(fin_res);
        free(fin_res);
    }
}

void append_c(string_t *this, const char *ap)
{
    char *final_res = NULL;

    if (this->str == NULL)
        this->assign_c(this, ap);
    else {
        final_res = malloc(sizeof(char) * (strlen(this->str) + strlen(ap) + 1));
        if (final_res == NULL)
            return;
        strcpy(final_res, this->str);
        strcpy(&final_res[strlen(this->str)], ap);
        string_destroy(this);
        this->str = strdup(final_res);
        free(final_res);
    }
}
