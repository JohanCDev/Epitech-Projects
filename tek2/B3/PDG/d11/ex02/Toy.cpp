/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Toy
*/

#include "Toy.hpp"

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

Toy::ToyType Toy::getType() const
{
    return this->_type;
}

std::string const &Toy::getName() const
{
    return this->_name;
}

void Toy::setName(std::string const &name)
{
    this->_name = name;
}

bool Toy::setAscii(const std::string &file)
{
    return this->_picture.getPictureFromFile(file);
}

std::string const &Toy::getAscii() const
{
    return this->_picture.data;
}

Toy &Toy::operator=(const Toy &copy)
{
    this->_type = copy._type;
    this->_name = copy._name;
    this->_picture = copy._picture;
    return *this;
}