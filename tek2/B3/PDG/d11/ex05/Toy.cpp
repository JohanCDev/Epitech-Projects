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

Toy::ToyType Toy::getType() const
{
    return this->_type;
}

std::string const &Toy::getName() const
{
    return this->_name;
}

std::string const &Toy::getAscii() const
{
    return this->_picture.data;
}

void Toy::setName(std::string const &name)
{
    this->_name = name;
}

bool Toy::setAscii(const std::string &file)
{
    bool res = this->_picture.getPictureFromFile(file);
    if (res)
        return true;
    this->_error.type = this->_error.PICTURE;
    this->_error._where = "setAscii";
    this->_error._what = "bad new illustration";
    return false;
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

bool Toy::speak_es(const std::string &statement)
{
    (void) statement;
    this->_error._what = "wrong mode";
    this->_error._where = "speak_es";
    this->_error.type = this->_error.SPEAK;
    return false;
}

Toy::Error const &Toy::getLastError() const
{
    return this->_error;
}

/* ERROR CLASS */
Toy::Error::Error()
{
    this->_what = "";
    this->_where = "";
    this->type = UNKNOWN;
}

Toy::Error::~Error()
{
}

const std::string& Toy::Error::what() const
{
    return this->_what;
}

const std::string& Toy::Error::where() const
{
    return this->_where;
}