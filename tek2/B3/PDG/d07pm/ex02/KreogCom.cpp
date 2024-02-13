/*
** EPITECH PROJECT, 2022
** Day07P
** File description:
** KreogCom
*/

#include "KreogCom.hpp"
#include <iostream>

KreogCom::KreogCom(int x, int y, int serial) : m_serial(serial)
{
    this->_pos_x = x;
    this->_pos_y = y;
    this->_next = nullptr;
    std::cout << "KreogCom " << this->m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *tmp = this->_next;

    this->_next = new KreogCom(x, y, serial);
    this->_next->_next = tmp;
}

KreogCom *KreogCom::getCom() const
{
    if (this->_next)
        return this->_next;
    return nullptr;
}

void KreogCom::removeCom()
{
    KreogCom *tmp = this->_next;

    if (this->_next)
        this->_next = this->_next->_next;
    else
        this->_next = nullptr;
    delete tmp;
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << this->m_serial << " currently at " << this->_pos_x << " " << this->_pos_y << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom *tmp = this->_next;

    while (tmp) {
        tmp->ping();
        tmp = tmp->_next;
    }
    this->ping();
}