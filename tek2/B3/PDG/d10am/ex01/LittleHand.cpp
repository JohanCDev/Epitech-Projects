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