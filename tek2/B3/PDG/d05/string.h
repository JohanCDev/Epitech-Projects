/*
** EPITECH PROJECT, 2020
** include my.h
** File description:
** desc
*/

#ifndef MY_H
    #define MY_H

// NEEDED INCLUDES
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdbool.h>

// MACROS

// STRUCTURES

typedef struct s_string string_t;
struct s_string {
    char *str;
    void (*assign_c)(string_t *this, const char *s);
    void (*assign_s)(string_t *this, const string_t *str);
    void (*append_s)(string_t *this, const string_t *ap);
    void (*append_c)(string_t *this, const char *ap);
    char (*at)(const string_t *this, size_t pos);
    void (*clear)(string_t *this);
    int (*length)(const string_t *this);
    int (*compare_c)(const string_t *this, const char *str);
    int (*compare_s)(const string_t *this, const string_t *str);
    size_t (*copy)(const string_t *this, char *s, size_t n, size_t pos);
    const char *(*c_str)(const string_t *this);
    int (*empty)(const string_t *this);
    int (*find_s)(const string_t *this, const string_t *str, size_t pos);
    int (*find_c)(const string_t *this, const char *str, size_t pos);
    void (*insert_c)(string_t *this, size_t pos, const char *str);
    void (*insert_s)(string_t *this, size_t pos, const string_t *str);
    int (*to_int)(const string_t *this);
};

// PROTOTYPES

// init_and_destroy.c
void string_init(string_t *this, const char *str);
void string_destroy(string_t *this);

// assign.c
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);

// append.c
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);

// at.c
char at(const string_t *this, size_t pos);

// clear.c
void clear(string_t *this);

// length.c
int length(const string_t *this);

// compare.c
int compare_c(const string_t *this, const char *str);
int compare_s(const string_t *this, const string_t *str);

// copy.c
size_t copy(const string_t *this, char *s, size_t n, size_t pos);

// contain.c
const char *c_str(const string_t *this);

// empty.c
int empty(const string_t *this);

// find.c
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);

// insert.c
void insert_c(string_t *this, size_t pos, const char *str);
void insert_s(string_t *this, size_t pos, const string_t *str);

// to_int.c
int to_int(const string_t *this);

#endif
