/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Circuit
*/

#include "Circuit.hpp"

nts::Circuit::Circuit() : AComponent("Main") {
    this->_tick = 0;
}

nts::Circuit::Circuit(const nts::Circuit &curr) : AComponent("Main") {
    this->_tick = curr._tick;
    this->_pins = curr._pins;
    this->_preceding = curr._preceding;
}

nts::Circuit::~Circuit() {
}

const nts::Circuit &nts::Circuit::operator=(const nts::Circuit &curr) {
    this->_tick = curr._tick;
    this->_pins = curr._pins;
    this->_preceding = curr._preceding;
    return *this;
}

void nts::Circuit::update_all(void)
{

}

size_t nts::Circuit::getTick(void) const
{
    return this->_tick;
}

nts::Tristate nts::Circuit::compute()
{
    return this->_state;
}

bool nts::Circuit::addComponent(std::shared_ptr<AComponent> newComponent)
{
    this->_pins.emplace_back(newComponent);
    return true;
}

size_t nts::Circuit::getCircuitSize(void) const
{
    return this->_pins.size();
}

void nts::Circuit::incrementTick(void)
{
    this->_tick += 1;
}