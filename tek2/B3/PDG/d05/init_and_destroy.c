/*
** EPITECH PROJECT, 2022
** Day05
** File description:
** init_and_destroy
*/

#include "string.h"
#include <stdlib.h>
#include <string.h>

void string_init(string_t *this, const char *str)
{
    if (str != NULL)
        this->str = strdup(str);
    this->assign_c = &assign_c;
    this->assign_s = &assign_s;
    this->append_c = &append_c;
    this->append_s = &append_s;
    this->at = &at;
    this->clear = &clear;
    this->length = &length;
    this->compare_c = &compare_c;
    this->compare_s = &compare_s;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_c = &find_c;
    this->find_s = &find_s;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
}

void string_destroy(string_t *this)
{
    if (this->str) {
        free(this->str);
        this->str = NULL;
    }
}
