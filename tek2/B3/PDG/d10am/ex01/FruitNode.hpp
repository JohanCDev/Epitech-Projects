/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD10am-johan.chrillesen
** File description:
** FruitNode
*/

#include "Fruit.hpp"
struct FruitNode
{
    FruitNode(Fruit *f) : next(nullptr), data(f){};
    ~FruitNode(){};
    FruitNode *next;
    Fruit *data;
};
