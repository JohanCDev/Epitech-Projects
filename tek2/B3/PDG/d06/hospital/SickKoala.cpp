/*
** EPITECH PROJECT, 2022
** Day06
** File description:
** SickKoala
*/

#include "SickKoala.hpp"
#include <iostream>
#include <string>

void printName(std::string name)
{
    std::cout << "Mr." << name << ": ";
}

SickKoala::SickKoala(std::string name)
{
    this->_name = name;
}

SickKoala::~SickKoala()
{
    printName(this->_name);
    std::cout << "Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke()
{
    printName(this->_name);
    std::cout << "Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
    printName(this->_name);
    if (str == "Mars") {
        std::cout << "Mars, and it kreogs!" << std::endl;
        return true;
    } else if (str == "Kinder") {
        std::cout << "There is a toy inside!" << std::endl;
        return true;
    } else
        std::cout << "Goerkreog!" << std::endl;
    return false;
}

void SickKoala::overDrive(std::string str)
{
    std::size_t pos = 0;

    while ((pos = str.find("Kreog!", pos)) != std::string::npos)
        str.replace(pos, 6, "1337!");
    printName(this->_name);
    std::cout << str << std::endl;
}

std::string SickKoala::getName()
{
    return this->_name;
}