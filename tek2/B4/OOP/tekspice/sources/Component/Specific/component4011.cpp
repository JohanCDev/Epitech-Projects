/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** component4011
*/

#include "component4011.hpp"

nts::Component4011::Component4011(const std::string &name) : AComponent(name)
{
    nts::NandGates first;
    nts::NandGates second;
    nts::NandGates third;
    nts::NandGates forth;
    nts::Electrical one;
    nts::Electrical two;

    this->_gates.emplace_back(first);
    this->_gates.emplace_back(second);
    this->_gates.emplace_back(third);
    this->_gates.emplace_back(forth);
    this->_unusedPins.emplace_back(one);
    this->_unusedPins.emplace_back(two);

    this->_pins.emplace_back(_gates[0].getPin(0));
    this->_pins.emplace_back(_gates[0].getPin(1));
    this->_pins.emplace_back(_gates[0].getPin(2));
    this->_pins.emplace_back(_gates[1].getPin(2));
    this->_pins.emplace_back(_gates[1].getPin(1));
    this->_pins.emplace_back(_gates[1].getPin(0));
    this->_pins.emplace_back(std::make_shared<Electrical>(_unusedPins[0]));
    this->_pins.emplace_back(_gates[2].getPin(0));
    this->_pins.emplace_back(_gates[2].getPin(1));
    this->_pins.emplace_back(_gates[2].getPin(2));
    this->_pins.emplace_back(_gates[3].getPin(2));
    this->_pins.emplace_back(_gates[3].getPin(1));
    this->_pins.emplace_back(_gates[3].getPin(0));
    this->_pins.emplace_back(std::make_shared<Electrical>(_unusedPins[1]));
}

nts::Tristate nts::Component4011::compute()
{
    for (size_t x = 0; x < _gates.size(); x++)
        _gates[x].compute();
    return UNDEFINED;
}