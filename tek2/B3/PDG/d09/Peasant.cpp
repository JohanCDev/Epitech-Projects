/*
** EPITECH PROJECT, 2022
** Day09
** File description:
** Peasant
*/

#include "Peasant.hpp"
#include <iostream>

Peasant::Peasant(const std::string &name, int power) : _name(name)
{
    this->_power = std::min(power, 100);
    this->_health = 100;
    std::cout << this->_name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << this->_name << " is back to his crops." << std::endl;
}

const std::string& Peasant::getName() const
{
    return this->_name;
}

int Peasant::getPower() const
{
    return this->_power;
}

int Peasant::getHp() const
{
    return this->_health;
}

int Peasant::attack()
{
    if (this->_health == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    } else if (this->_power < 10) {
        std::cout << this->_name << " is out of power." << std::endl;
        return 0;
    } else {
        this->_power -= 10;
        std::cout << this->_name << " tosses a stone." << std::endl;
        return 5;
    }
    return 0;
}

int Peasant::special()
{
    if (this->_health == 0)
        std::cout << this->_name << " is out of combat." << std::endl;
    else
        std::cout << this->_name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (this->_health == 0)
        std::cout << this->_name << " is out of combat." << std::endl;
    else {
        this->_power = this->_power + 30 > 100 ? 100 : this->_power + 30;
        std::cout << this->_name << " takes a nap." << std::endl;
    }
}

void Peasant::damage(int damage)
{
    int health;

    if (this->_health > 0) {
        health = std::max(0, this->_health - damage);
        this->_health = health;
        if (this->_health > 0)
            std::cout << this->_name << " takes " << damage << " damage." << std::endl;
    }
    if (this->_health <= 0)
        std::cout << this->_name << " is out of combat." << std::endl;
}


