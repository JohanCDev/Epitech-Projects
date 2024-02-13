/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** Input
*/

#include "Input.hpp"

nts::Input::Input(const std::string &name, nts::Tristate state) : AComponent(name, INPUT, state)
{

}

nts::Tristate nts::Input::compute()
{
    return this->_state;
}