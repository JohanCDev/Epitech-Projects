/*
** EPITECH PROJECT, 2022
** DAY07A
** File description:
** Admiral
*/

#include "Admiral.hpp"
#include <iostream>

Federation::Starfleet::Admiral::Admiral(std::string name)
{
    this->_name = name;
    std::cout <<  "Admiral " << this->_name << " ready for action." << std::endl;
}

Federation::Starfleet::Admiral::~Admiral()
{
}

void Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship *ship, Borg::Ship *target)
{
    std::cout << "On order from Admiral " << this->_name << ":" << std::endl;
    (*ship.*firePtr)(target);
}

bool Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship *ship, Destination dest)
{
    return (*ship.*movePtr)(dest);
}
