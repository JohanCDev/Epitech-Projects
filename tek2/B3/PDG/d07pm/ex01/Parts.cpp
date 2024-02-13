/*
** EPITECH PROJECT, 2022
** Day07P
** File description:
** Parts
*/

#include "Parts.hpp"
#include <iostream>

/* HEAD CLASS */
Head::Head(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

Head::~Head()
{
}

bool Head::isFunctionnal() const
{
    return this->_functionnal;
}

std::string Head::serial() const
{
    return this->_serial;
}

void Head::informations() const
{
    std::cout << "\t[Parts] Head " << this->_serial << " status : " << (this->_functionnal ? "OK" : "KO") << std::endl;
}

/* LEGS CLASS */
Legs::Legs(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

Legs::~Legs()
{
}

bool Legs::isFunctionnal() const
{
    return this->_functionnal;
}

std::string Legs::serial() const
{
    return this->_serial;
}

void Legs::informations() const
{
    std::cout << "\t[Parts] Legs " << this->_serial << " status : " << (this->_functionnal ? "OK" : "KO") << std::endl;
}

/* ARMS CLASS */
Arms::Arms(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

Arms::~Arms()
{
}

bool Arms::isFunctionnal() const
{
    return this->_functionnal;
}

std::string Arms::serial() const
{
    return this->_serial;
}

void Arms::informations() const
{
    std::cout << "\t[Parts] Arms " << this->_serial << " status : " << (this->_functionnal ? "OK" : "KO") << std::endl;
}