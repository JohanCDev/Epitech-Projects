/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** Clock
*/

#include "Clock.hpp"

nts::Clock::Clock(nts::Tristate state, const std::string &name) : AComponent(name, COMPONENT, state)
{

}

nts::Tristate nts::Clock::compute()
{
    //In Main Loop, if Component == Clock && Clock->getState() != Undefined
    //                  Clock->setState(!Clock_state);
    return this->_state;
}
