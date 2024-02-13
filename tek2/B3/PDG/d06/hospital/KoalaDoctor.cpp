/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"
#include "SickKoala.hpp"
#include <iostream>
#include <fstream>

void printDoctor(std::string name)
{
    std::cout << "Dr." << name << ": ";
}

KoalaDoctor::KoalaDoctor(std::string name)
{
    this->_name = name;
    this->_is_working = false;
    printDoctor(this->_name);
    std::cout << "I'm Dr." << this->_name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *koala)
{
    std::string drugs[5] = {"Mars", "Kinder","Crunch", "Maroilles", "Eucalyptus leaf"};
    std::string koala_name = koala->getName();
    std::string filename = koala_name + ".report";
    std::ofstream file (filename);

    printDoctor(this->_name);
    std::cout << "So what's goerking you Mr." << koala->getName() << "?" << std::endl;
    koala->poke();
    file << drugs[random() % 5] << std::endl;
}

void KoalaDoctor::timeCheck()
{
    if (!this->_is_working) {
        this->_is_working = true;
        printDoctor(this->_name);
        std::cout << "Time to get to work!" << std::endl;
    } else {
        this->_is_working = false;
        printDoctor(this->_name);
        std::cout << "Time to go home to my eucalyptus forest!" << std::endl;
    }
}

std::string KoalaDoctor::getName()
{
    return this->_name;
}
