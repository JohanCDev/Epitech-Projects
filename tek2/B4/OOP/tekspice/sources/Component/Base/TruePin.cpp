/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** True
*/

#include "TruePin.hpp"

nts::TruePin::TruePin(const std::string &name) : AComponent(name, COMPONENT, TRUE)
{

}

nts::Tristate nts::TruePin::compute()
{
    return nts::TRUE;
}