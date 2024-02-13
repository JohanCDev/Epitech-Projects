/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** OrGates
*/

#include "OrGates.hpp"
#include <iostream>

nts::OrGates::OrGates(const std::string &name) : AComponent(name, COMPONENT)
{
    this->_pins.emplace_back(std::make_shared<Input>());
    this->_pins.emplace_back(std::make_shared<Input>());
    this->_pins.emplace_back(std::make_shared<Output>());
}

nts::Tristate nts::OrGates::compute()
{
    if (this->_pins[0].get()->getState() != UNDEFINED && this->_pins[1].get()->getState() != UNDEFINED) {
        if (this->_pins[0].get()->getState() != this->_pins[1].get()->getState())
            return TRUE;
        else
            return FALSE;
    } else {
        return UNDEFINED;
    }
}