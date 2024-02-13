/*
** EPITECH PROJECT, 2022
** Day09
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Enchanter.hpp"

class Priest : virtual public Enchanter
{
    public:
        Priest(const std::string &, int);
        ~Priest();
        void rest();

    protected:
    private:
};

#endif /* !PRIEST_HPP_ */