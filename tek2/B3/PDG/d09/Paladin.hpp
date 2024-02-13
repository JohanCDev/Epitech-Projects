/*
** EPITECH PROJECT, 2022
** Day09
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Knight.hpp"
#include "Priest.hpp"

class Paladin : virtual public Knight, virtual public Priest
{
    public:
        Paladin(const std::string &, int);
        ~Paladin();
        int attack();
        int special();
        void rest();
        void damage(int);

    protected:
    private:
};

#endif /* !PALADIN_HPP_ */
