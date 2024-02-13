/*
** EPITECH PROJECT, 2022
** Day09
** File description:
** Knight
*/

#include "Knight.hpp"
#include <iostream>

Knight::Knight(const std::string &name, int power): Peasant(name, power)
{
    std::cout << this->_name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << this->_name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    } else if (this->_power < 10) {
        std::cout << this->_name << " is out of power." << std::endl;
        return 0;
    } else {
        this->_power -= 10;
        std::cout << this->_name << " strikes with his sword." << std::endl;
        return 20;
    }
    return 0;
}

int Knight::special()
{
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    } else {
        if (this->_power >= 30) {
            this->_power -= 30;
            std::cout << this->_name << " impales his enemy." << std::endl;
            return 50;
        } else {
            std::cout << this->_name << " is out of power." << std::endl;
            return 0;
        }
    }
}

void Knight::rest()
{
    if (this->_health == 0)
        std::cout << this->_name << " is out of combat." << std::endl;
    else {
        this->_power = this->_power + 50 > 100 ? 100 : this->_power + 50;
        std::cout << this->_name << " eats." << std::endl;
    }
}