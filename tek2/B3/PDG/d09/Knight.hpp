/*
** EPITECH PROJECT, 2022
** Day09
** File description:
** Knight
*/

#ifndef __KNIGHT__
#define __KNIGHT__

#include "Peasant.hpp"

class Knight : virtual public Peasant
{
    public:
        Knight(const std::string &, int);
        ~Knight();
        int attack();
        int special();
        void rest();
};

#endif
