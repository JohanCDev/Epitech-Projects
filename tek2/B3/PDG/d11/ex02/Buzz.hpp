/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy
{
    public:
        Buzz(std::string, std::string = "buzz.txt");
        ~Buzz();

    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
