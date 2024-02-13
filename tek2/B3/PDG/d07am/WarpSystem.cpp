/*
** EPITECH PROJECT, 2022
** DAY07A
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
{
    this->_stability = true;
}

WarpSystem::Core::Core(QuantumReactor *reactor)
{
    this->_coreReactor = reactor;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

WarpSystem::Core::~Core()
{
}

bool WarpSystem::QuantumReactor::isStable()
{
    return this->_stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return this->_coreReactor;
}