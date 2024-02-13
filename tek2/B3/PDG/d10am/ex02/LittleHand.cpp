/*
** EPITECH PROJECT, 2022
** Day10AM
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    FruitBox tmpUnsort(unsorted.nbFruits());
    Fruit *fruit = unsorted.pickFruit();

    while (fruit) {
        if (fruit->getVitamins() == 3) {
            if (lemons.putFruit(fruit) == false)
                tmpUnsort.putFruit(fruit);
        } else if (fruit->getVitamins() == 2) {
            if (limes.putFruit(fruit) == false)
                tmpUnsort.putFruit(fruit);
        } else if (fruit->getVitamins() == 5) {
            if (bananas.putFruit(fruit) == false)
               tmpUnsort.putFruit(fruit);
        } else
            tmpUnsort.putFruit(fruit);
        fruit = unsorted.pickFruit();
    }
    fruit = tmpUnsort.pickFruit();
    while (fruit) {
        unsorted.putFruit(fruit);
        fruit = tmpUnsort.pickFruit();
    }
}

FruitBox *const *LittleHand::organizeCoconut(Coconut *const *coconuts)
{
    FruitBox **finalBox = nullptr;
    size_t size = 0;
    Coconut *coconutTmp;
    int j = 0;

    for (; coconuts[size]; size++);
    finalBox = new FruitBox*[size / 6 + 1];
    for (int i = 0; coconuts[i]; j++) {
        finalBox[j] = new FruitBox(6);
        for (int k = 0; k < 6; k++, i++) {
            if (coconuts[i]) {
                coconutTmp = coconuts[i];
                finalBox[j]->putFruit(coconutTmp);
            } else {
                finalBox[j + 1] = nullptr;
                return finalBox;
            }
        }
    }
    return nullptr;
}