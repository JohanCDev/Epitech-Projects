/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** KoalaNurseList
*/

#include "KoalaNurseList.hpp"
#include <iostream>

KoalaNurseList::KoalaNurseList(KoalaNurse *nurse)
{
    this->data = nurse;
    this->next = nullptr;
}

KoalaNurseList::~KoalaNurseList()
{
}

bool KoalaNurseList::isEnd()
{
    if (this->next == nullptr)
        return true;
    return false;
}

void KoalaNurseList::append(KoalaNurseList *new_nurse)
{
    if (this->isEnd())
        this->next = new_nurse;
    else
        this->next->append(new_nurse);
}

KoalaNurse *KoalaNurseList::getFromID(int nurseID)
{
    if (this->data && this->data->getID() == nurseID)
        return this->data;
    else if (this->next)
        return this->next->getFromID(nurseID);
    return nullptr;
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *to_remove)
{
    KoalaNurseList *tmp = this->next;

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

KoalaNurseList *KoalaNurseList::removeFromID(int ID)
{
    KoalaNurseList *tmp = this->next;

    if (this->data->getID() == ID) {
        this->next = nullptr;
        return tmp;
    }
    if (this->next) {
        if (this->next->data->getID() == ID)
            this->next = this->next->getNext();
        else
            this->next->removeFromID(ID);
    }
    return this;
}

KoalaNurse *KoalaNurseList::getContent()
{
    return this->data;
}

KoalaNurseList *KoalaNurseList::getNext()
{
    return this->next;
}

void KoalaNurseList::dump()
{
    KoalaNurseList *tmp = this;

    std::cout << "Nurses: ";
    while (tmp) {
        if (tmp->data)
            std::cout << tmp->data->getID();
        else
            std::cout << "[nullptr]";
        if (tmp->next)
            std::cout << ", ";
        else
            std::cout << "." << std::endl;
        tmp = tmp->next;
    }
}
