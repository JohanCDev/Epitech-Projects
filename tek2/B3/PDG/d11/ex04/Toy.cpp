/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Toy
*/

#include "Toy.hpp"
#include <iostream>

Toy::Toy()
{
    this->_type = this->BASIC_TOY;
    this->_name = "toy";
    this->_picture.data = "";
}

Toy::Toy(ToyType type, std::string name, std::string filename)
{
    this->_picture.getPictureFromFile(filename);
    this->_type = type;
    this->_name = name;
}

Toy::~Toy()
{
}

Toy::ToyType Toy::getType()
{
    return this->_type;
}

std::string Toy::getName()
{
    return this->_name;
}

std::string Toy::getAscii()
{
    return this->_picture.data;
}

void Toy::setName(std::string name)
{
    this->_name = name;
}

bool Toy::setAscii(const std::string &file)
{
    return this->_picture.getPictureFromFile(file);
}


Toy &Toy::operator=(const Toy &copy)
{
    this->_type = copy._type;
    this->_name = copy._name;
    this->_picture = copy._picture;
    return *this;
}

std::ostream &operator<<(std::ostream &os, Toy &toy)
{
    return (os << toy.getName() << std::endl << toy.getAscii() << std::endl);
}

Toy &Toy::operator<<(const char *ascii)
{
    this->_picture.data = ascii;
    return *this;
}

void Toy::speak(const std::string &statement)
{
    std::cout << this->_name << " \"" <<  statement << "\"" << std::endl;
}