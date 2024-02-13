/*
** EPITECH PROJECT, 2022
** Day10AM
** File description:
** LittleHand
*/

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

#include "FruitBox.hpp"

class LittleHand
{
    public:
        LittleHand();
        virtual ~LittleHand(){};
        static void sortFruitBox(FruitBox &, FruitBox &, FruitBox &, FruitBox &);
        FruitBox *const *organizeCoconut(Coconut *const *);
};

#endif /* !LITTLEHAND_HPP_ */
