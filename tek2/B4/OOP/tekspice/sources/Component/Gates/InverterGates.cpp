/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** InverterGates
*/

#include "InverterGates.hpp"

nts::InverterGates::InverterGates(const std::string &name) : AComponent(name, COMPONENT)
{
    this->_pins.emplace_back(std::make_shared<Input>());
    this->_pins.emplace_back(std::make_shared<Output>());
}

nts::Tristate nts::InverterGates::compute()
{
    nts::Tristate state = this->_pins[0].get()->getState();

    if (state != UNDEFINED) {
        if (state == TRUE)
            state = FALSE;
        else
            state = TRUE;
    }
    return state;
}