/*
** EPITECH PROJECT, 2022
** Day07P
** File description:
** KoalaBot
*/

#include "Parts.hpp"
#include <iostream>
#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial)
{
    this->_serial = serial;
}

void KoalaBot::setParts(const Arms &arms)
{
    this->_Arms = arms;
}

void KoalaBot::setParts(const Legs &legs)
{
    this->_Legs = legs;
}

void KoalaBot::setParts(const Head &head)
{
    this->_Head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    Arms tmp = arms;

    arms = this->_Arms;
    this->setParts(tmp);
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs tmp = legs;

    legs = this->_Legs;
    this->setParts(tmp);
}

void KoalaBot::swapParts(Head &head)
{
    Head tmp = head;

    head = this->_Head;
    this->setParts(tmp);
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    this->_Arms.informations();
    this->_Legs.informations();
    this->_Head.informations();
}

bool KoalaBot::status() const
{
    return (this->_Arms.isFunctionnal() && this->_Legs.isFunctionnal() && this->_Head.isFunctionnal());
}

KoalaBot::~KoalaBot()
{
}
