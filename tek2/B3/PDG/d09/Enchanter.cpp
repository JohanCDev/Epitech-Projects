/*
** EPITECH PROJECT, 2022
** Day09
** File description:
** Enchanter
*/

#include "Enchanter.hpp"
#include <iostream>

Enchanter::Enchanter(const std::string &name, int power): Peasant(name, power)
{
    std::cout << this->_name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << this->_name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (this->_health == 0)
        std::cout << this->_name << " is out of combat." << std::endl;
    else
        std::cout << this->_name << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special()
{
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    } else {
        if (this->_power >= 50) {
            this->_power -= 50;
            std::cout << this->_name << " casts a fireball." << std::endl;
            return 99;
        } else {
            std::cout << this->_name << " is out of power." << std::endl;
            return 0;
        }
    }
}

void Enchanter::rest()
{
    if (this->_health == 0)
        std::cout << this->_name << " is out of combat." << std::endl;
    else {
        this->_power = 100;
        std::cout << this->_name << " meditates." << std::endl;
    }
}