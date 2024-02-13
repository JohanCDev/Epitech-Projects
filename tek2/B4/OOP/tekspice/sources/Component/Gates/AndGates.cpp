/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** AndGates
*/

#include "AndGates.hpp"

nts::AndGates::AndGates(const std::string &name) : AComponent(name, COMPONENT)
{
    this->_pins.emplace_back(std::make_shared<Input>());
    this->_pins.emplace_back(std::make_shared<Input>());
    this->_pins.emplace_back(std::make_shared<Output>());
}

nts::Tristate nts::AndGates::compute()
{
    if (this->_pins[0].get()->getState() != UNDEFINED && this->_pins[1].get()->getState() != UNDEFINED) {
        if (this->_pins[0].get()->getState() && this->_pins[1].get()->getState())
            return TRUE;
        else
            return FALSE;
    } else {
        return UNDEFINED;
    }
}