/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** SickKoalaList
*/

#include "SickKoalaList.hpp"
#include <iostream>

SickKoalaList::SickKoalaList(SickKoala *koala)
{
    this->data = koala;
    this->next = nullptr;
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd()
{
    if (this->next == nullptr)
        return true;
    return false;
}

void SickKoalaList::append(SickKoalaList *new_koala)
{
    if (this->isEnd())
        this->next = new_koala;
    else
        this->next->append(new_koala);
}

SickKoala *SickKoalaList::getFromName(std::string koala)
{
    if (this->data && this->data->getName() == koala)
        return this->data;
    else if (this->next)
        return this->next->getFromName(koala);
    return nullptr;
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *to_remove)
{
    SickKoalaList *tmp = this->next;

    if (!to_remove)
        return this;
    if (this == to_remove) {
        this->next = nullptr;
        return tmp;
    }
    if (this->next) {
        if (this->next == to_remove)
            this->next = this->next->getNext();
        else
            this->next->remove(to_remove);
    }
    return this;
}

SickKoalaList *SickKoalaList::removeFromName(std::string str)
{
    SickKoalaList *tmp = this->next;

    if (this->data->getName() == str) {
        this->next = nullptr;
        return tmp;
    }
    if (this->next) {
        if (this->next->data->getName() == str)
            this->next = this->next->getNext();
        else
            this->next->removeFromName(str);
    }
    return this;
}

SickKoala *SickKoalaList::getContent()
{
    return this->data;
}

SickKoalaList *SickKoalaList::getNext()
{
    return this->next;
}

void SickKoalaList::dump()
{
    SickKoalaList *tmp = this;

    std::cout << "Patients: ";
    while (tmp) {
        if (tmp->data)
            std::cout << tmp->data->getName();
        else
            std::cout << "[nullptr]";
        if (tmp->next)
            std::cout << ", ";
        else
            std::cout << "." << std::endl;
        tmp = tmp->next;
    }
}
