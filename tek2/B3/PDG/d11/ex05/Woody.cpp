/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Woody
*/

#include "Woody.hpp"
#include <iostream>

Woody::Woody(std::string name, std::string filename) : Toy(ToyType::WOODY, name, filename) {}

Woody::~Woody()
{
}

void Woody::speak(const std::string &statement)
{
    std::cout << "WOODY: " << this->getName() << " \"" << statement << "\"" << std::endl;
}