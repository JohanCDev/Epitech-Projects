/*
** EPITECH PROJECT, 2022
** Day07P
** File description:
** Skat
*/

#include "Skat.hpp"
#include <iostream>

Skat::Skat(const std::string name, int stimPaks)
{
    this->_name = name;
    this->_stimPaks = stimPaks;
}

Skat::~Skat()
{
}

int &Skat::stimPaks()
{
    return this->_stimPaks;
}

const std::string &Skat::name()
{
    return this->_name;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number <= this->_stimPaks) {
        this->_stimPaks -= number;
        stock += number;
        std::cout << "Keep the change." << std::endl;
    } else
        std::cout << "Don't be greedy" << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    else
        this->_stimPaks += number;
}

void Skat::useStimPaks()
{
    if (this->_stimPaks == 0)
        std::cout << "Mediiiiiic" << std::endl;
    else {
        this->_stimPaks -= 1;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    }
}

void Skat::status()
{
    std::cout << "Soldier " << this->_name << " reporting " << this->_stimPaks << " stimpaks remaining sir!" << std::endl;
}