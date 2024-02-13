/*
** EPITECH PROJECT, 2022
** Day09
** File description:
** Echanter
*/

#ifndef __ENCHANTER__
#define __ENCHANTER__

#include "Peasant.hpp"

class Enchanter : virtual public Peasant
{
    public:
        Enchanter(const std::string &, int);
        ~Enchanter();
        virtual int attack();
        virtual int special();
        virtual void rest();
};

#endif
