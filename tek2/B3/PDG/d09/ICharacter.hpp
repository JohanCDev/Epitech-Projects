/*
** EPITECH PROJECT, 2022
** Day09
** File description:
** ICharacter
*/

#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_

#include <string>

class ICharacter {
    public:
        virtual ~ICharacter(){};
        virtual int getHp() const = 0;
        virtual int getPower() const = 0;
        virtual const std::string &getName() const = 0;
        virtual int attack() = 0;
        virtual int special() = 0;
        virtual void rest() = 0;
        virtual void damage(int) = 0;

    protected:
        int _health;
        int _power;
        const std::string _name;
};

#endif /* !ICHARACTER_HPP_ */
