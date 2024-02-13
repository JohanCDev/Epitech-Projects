/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Buzz
*/

#include "Buzz.hpp"
#include <iostream>

Buzz::Buzz(std::string name, std::string filename) : Toy(ToyType::BUZZ, name, filename) {}

Buzz::~Buzz()
{
}

void Buzz::speak(const std::string &statement)
{
    std::cout << "BUZZ: " << this->getName() << " \"" << statement << "\"" << std::endl;
}

bool Buzz::speak_es(const std::string &statement)
{
    std::cout << "BUZZ: " << this->getName() << " senorita \"" << statement << "\" senorita" << std::endl;
    return true;
}