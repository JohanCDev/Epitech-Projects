/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** NorGates
*/

#include "NorGates.hpp"

nts::NorGates::NorGates(const std::string &name) : AComponent(name, COMPONENT)
{
    this->_pins.emplace_back(std::make_shared<Input>());
    this->_pins.emplace_back(std::make_shared<Input>());
    this->_pins.emplace_back(std::make_shared<Output>());
}

nts::Tristate nts::NorGates::compute()
{
    if (this->_pins[0].get()->getState() != UNDEFINED && this->_pins[1].get()->getState() != UNDEFINED) {
        if (this->_pins[0].get()->getState() == FALSE && this->_pins[1].get()->getState() == FALSE)
            return TRUE;
        else
            return FALSE;
    } else {
        return UNDEFINED;
    }
}
