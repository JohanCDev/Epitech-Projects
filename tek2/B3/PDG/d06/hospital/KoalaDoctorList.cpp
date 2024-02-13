/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** koaladoctorlist
*/

#include "KoalaDoctorList.hpp"
#include <iostream>

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *koala)
{
    this->data = koala;
    this->next = nullptr;
}

KoalaDoctorList::~KoalaDoctorList()
{
}

bool KoalaDoctorList::isEnd()
{
    if (this->next == nullptr)
        return true;
    return false;
}

void KoalaDoctorList::append(KoalaDoctorList *new_doctor)
{
    if (this->isEnd())
        this->next = new_doctor;
    else
        this->next->append(new_doctor);
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string doctor)
{
    if (this->data && this->data->getName() == doctor)
        return this->data;
    else if (this->next)
        return this->next->getFromName(doctor);
    return nullptr;
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *to_remove)
{
    KoalaDoctorList *tmp = this->next;

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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string str)
{
    KoalaDoctorList *tmp = this->next;

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

KoalaDoctor *KoalaDoctorList::getContent()
{
    return this->data;
}

KoalaDoctorList *KoalaDoctorList::getNext()
{
    return this->next;
}

void KoalaDoctorList::dump()
{
    KoalaDoctorList *tmp = this;

    std::cout << "Doctors: ";
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
