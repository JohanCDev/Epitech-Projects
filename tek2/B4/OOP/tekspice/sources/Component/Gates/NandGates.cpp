/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** NandGates
*/

#include "NandGates.hpp"

nts::NandGates::NandGates(const std::string &name) : AComponent(name, COMPONENT)
{
    this->_pins.emplace_back(std::make_shared<Input>());
    this->_pins.emplace_back(std::make_shared<Input>());
    this->_pins.emplace_back(std::make_shared<Output>());
}

nts::Tristate nts::NandGates::compute()
{
    if (this->_pins[0].get()->getState() != UNDEFINED && this->_pins[1].get()->getState() != UNDEFINED) {
        if (this->_pins[0].get()->getState() && this->_pins[1].get()->getState())
            return FALSE;
        else
            return TRUE;
    } else {
        return UNDEFINED;
    }
}