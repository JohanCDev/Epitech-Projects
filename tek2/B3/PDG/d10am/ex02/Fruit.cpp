/*
** EPITECH PROJECT, 2022
** Day10AM
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(std::string name, int vitamins)
{
    this->_name = name;
    this->_vitamins = vitamins;
}

std::string Fruit::getName()
{
    return this->_name;
}

int Fruit::getVitamins()
{
    return this->_vitamins;
}
