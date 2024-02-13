/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD10am-johan.chrillesen
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"
#include "Coconut.hpp"

class FruitBox {
    public:
        FruitBox(int);
        virtual ~FruitBox(){};
        int nbFruits() const;
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head() const;

    protected:
    private:
        int _size;
        int _sizeMax;
        FruitNode *FruitsList;
};

#endif /* !FRUITBOX_HPP_ */
