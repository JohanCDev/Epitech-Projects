/*
** EPITECH PROJECT, 2021
** sandpile.h
** File description:
** sandpile.h
*/


#ifndef __SANDPILE__
#define __SANDPILE__

//-----NEEDED-INCLUDE------
#include "struct.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
//-----MACROS--------------

//-----STRUCTURE-----------

//-----PROTOTYPES----------
int print_sandpile(map_t *map);
int sandpile(map_t *map, int nb_cycle);

#endif