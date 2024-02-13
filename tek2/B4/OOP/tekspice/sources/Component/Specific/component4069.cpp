/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** component4069
*/

#include "component4069.hpp"

nts::Component4069::Component4069(const std::string &name) : AComponent(name)
{
    nts::InverterGates first;
    nts::InverterGates second;
    nts::InverterGates third;
    nts::InverterGates forth;
    nts::InverterGates fifth;
    nts::InverterGates sixth;
    nts::Electrical one;
    nts::Electrical two;

    this->_gates.emplace_back(first);
    this->_gates.emplace_back(second);
    this->_gates.emplace_back(third);
    this->_gates.emplace_back(forth);
    this->_gates.emplace_back(fifth);
    this->_gates.emplace_back(sixth);
    this->_unusedPins.emplace_back(one);
    this->_unusedPins.emplace_back(two);

    this->_pins.emplace_back(_gates[0].getPin(0));
    this->_pins.emplace_back(_gates[0].getPin(1));
    this->_pins.emplace_back(_gates[1].getPin(0));
    this->_pins.emplace_back(_gates[1].getPin(1));
    this->_pins.emplace_back(_gates[2].getPin(0));
    this->_pins.emplace_back(_gates[2].getPin(1));
    this->_pins.emplace_back(std::make_shared<Electrical>(_unusedPins[0]));
    this->_pins.emplace_back(_gates[3].getPin(1));
    this->_pins.emplace_back(_gates[3].getPin(0));
    this->_pins.emplace_back(_gates[4].getPin(1));
    this->_pins.emplace_back(_gates[4].getPin(0));
    this->_pins.emplace_back(_gates[5].getPin(1));
    this->_pins.emplace_back(_gates[5].getPin(0));
    this->_pins.emplace_back(std::make_shared<Electrical>(_unusedPins[1]));
}

nts::Tristate nts::Component4069::compute()
{
    for (size_t x = 0; x < _gates.size(); x++)
        _gates[x].compute();
    return UNDEFINED;
}