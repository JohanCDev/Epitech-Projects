/*
** EPITECH PROJECT, 2022
** Day09
** File description:
** Peasant
*/

#ifndef __PEASANT__
#define __PEASANT__

#include <string>
#include "ICharacter.hpp"

class Peasant : virtual public ICharacter
{
    public:
        Peasant(const std::string &, int);
        ~Peasant();
        const std::string &getName() const;
        int getPower() const;
        int getHp() const;
        virtual int attack();
        virtual int special();
        virtual void rest();
        virtual void damage(int);

    protected:
        int _power;
        int _health;
        const std::string _name;
};

#endif
