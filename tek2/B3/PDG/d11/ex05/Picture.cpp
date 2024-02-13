/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Picture
*/

#include "Picture.hpp"
#include <fstream>
#include <sstream>

Picture::Picture()
{
    this->data = "";
}

Picture::Picture(const std::string &file)
{
    this->data = this->getPictureFromFile(file);
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream f(file);

    if (f.is_open()) {
        std::stringstream buff;
        buff << f.rdbuf();
        this->data = buff.str();
    } else {
        this->data = "ERROR";
        return false;
    }
    return true;
}

Picture& Picture::operator=(const Picture &copy)
{
    this->data = copy.data;
    return *this;
}