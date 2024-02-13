/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD10am-johan.chrillesen
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    this->_sizeMax = size;
    this->_size = 0;
    this->FruitsList = nullptr;
}

int FruitBox::nbFruits() const
{
    return this->_size;
}

FruitNode *FruitBox::head() const
{
    return this->FruitsList;
}

bool FruitBox::putFruit(Fruit *f)
{
    if (this->_size == 0) {
        this->_size++;
        this->FruitsList = new FruitNode(f);
        return true;
    } else if (this->_size == this->_sizeMax) {
        return false;
    } else {
        FruitNode *tmp = this->head();
        while (tmp->next)
        {
            if (tmp->data == f)
                return false;
            tmp = tmp->next;
        }
        tmp->next = new FruitNode(f);
        this->_size++;
        return true;
    }
    return false;
}

Fruit *FruitBox::pickFruit()
{
    Fruit *tmp = nullptr;
    if (this->FruitsList == NULL)
        return(NULL);
    tmp = this->FruitsList->data;
    this->FruitsList = this->FruitsList->next;
    this->_size--;
    return tmp;
}
