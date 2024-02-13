/*
** EPITECH PROJECT, 2022
** Day10AM
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <string>

class Fruit {
    public:
        virtual ~Fruit(){};
        std::string getName();
        int getVitamins();

    protected:
        Fruit(std::string, int);
        Fruit(){this->_vitamins = 0;};
        int _vitamins;
        std::string _name;
};

#endif /* !FRUIT_HPP_ */
