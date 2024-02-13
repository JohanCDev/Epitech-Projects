/*
** EPITECH PROJECT, 2022
** Day10AM
** File description:
** Lime
*/

#ifndef LIME_HPP_
#define LIME_HPP_

#include "Lemon.hpp"
#include "Fruit.hpp"

class Lime : virtual public Fruit, virtual public Lemon
{
    public:
        Lime();
        virtual ~Lime(){};

    protected:
    private:
};

#endif /* !LIME_HPP_ */
