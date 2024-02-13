/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** AComponent
*/

#include "AComponent.hpp"

#include <iomanip>
#include <iostream>

nts::AComponent::AComponent(const std::string &name, Usestate use, Tristate state) : _name(name), _use(use), _state(state) {
}

void nts::AComponent::setLink(size_t pin, nts::IComponent &other, size_t otherPin) {
    // Vérifié dans la théorie
    this->_pins[pin].get()->_preceding.emplace_back(reinterpret_cast<AComponent &>(other)._pins[otherPin]);
}

bool nts::AComponent::usable(nts::Usestate use) {
    return use > 0 ? true : false;
}

void nts::AComponent::simulate(size_t tick) {
    (void)tick;

    for (size_t x = 0; x < _pins.size(); x++) {
        if (usable(this->_pins[x].get()->getUse()) && this->_pins[x].get()->getState() == UNDEFINED) {
            this->_pins[x].get()->_state = compute();
        }
    }
}

std::string nts::AComponent::getStrUse(void) const {
    switch (this->_use) {
        case ELECTRICAL:
            return "ELECTRICAL";
        case COMPONENT:
            return "COMPONENT";
        case INPUT:
            return "INPUT";
        case OUTPUT:
            return "OUTPUT";
        default:
            return "PROBLEM";
    }
}

std::string nts::AComponent::getStrState(void) const {
    switch (this->_state) {
        case UNDEFINED:
            return "UNDEFINED";
        case TRUE:
            return "TRUE";
        case FALSE:
            return "FALSE";
        default:
            return "PROBLEM";
    }
}

void nts::AComponent::dump(void) const {
    std::cout << this->_name << std::endl;
    std::cout << std::setw(16);
    std::cout << getStrUse() << std::endl;
    std::cout << std::setw(16);
    std::cout << getStrState() << std::endl;
}

nts::Usestate nts::AComponent::getUse(void) const {
    return this->_use;
}

nts::Tristate nts::AComponent::getState(void) const {
    return this->_state;
}

void nts::AComponent::setState(nts::Tristate newState) {
    this->_state = newState;
}

std::shared_ptr<nts::AComponent> nts::AComponent::getPin(size_t pin) const
{
    return this->_pins[pin];
}

const std::string &nts::AComponent::getName(void) const
{
    return this->_name;
}