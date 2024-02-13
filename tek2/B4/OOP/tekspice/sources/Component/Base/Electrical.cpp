/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** Electrical
*/

#include "Electrical.hpp"

nts::Electrical::Electrical(const std::string &name) : AComponent(name, ELECTRICAL)
{

}

nts::Tristate nts::Electrical::compute()
{
    //Raise Exception
    return UNDEFINED;
}