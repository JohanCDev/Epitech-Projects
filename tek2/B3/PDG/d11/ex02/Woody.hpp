/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy
{
    public:
        Woody(std::string, std::string = "woody.txt");
        ~Woody();

    protected:
    private:
};

#endif /* !WOODY_HPP_ */
