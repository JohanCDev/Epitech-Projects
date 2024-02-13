/*
** EPITECH PROJECT, 2022
** Day09
** File description:
** Paladin
*/

#include "Paladin.hpp"
#include <iostream>

Paladin::Paladin(const std::string &name, int power) : Peasant(name, power), Knight(name, power), Enchanter(name, power), Priest(name, power)
{
    std::cout << this->Knight::_name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << this->Knight::_name << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return this->Knight::attack();
}

int Paladin::special()
{
    return this->Enchanter::special();
}

void Paladin::rest()
{
    this->Priest::rest();
}

void Paladin::damage(int damage)
{
    this->Priest::damage(damage);
}