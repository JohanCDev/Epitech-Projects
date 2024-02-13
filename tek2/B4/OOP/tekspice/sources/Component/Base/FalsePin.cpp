/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** FalsePin
*/

#include "FalsePin.hpp"

nts::FalsePin::FalsePin(const std::string &name) : AComponent(name, COMPONENT, FALSE)
{

}

nts::Tristate nts::FalsePin::compute()
{
    return nts::FALSE;
}