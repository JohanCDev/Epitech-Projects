/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** Output
*/

#include "Output.hpp"

nts::Output::Output(const std::string &name, nts::Tristate state) : AComponent(name, OUTPUT, state)
{

}

nts::Tristate nts::Output::compute()
{
    //TO DO : Get preceding if _state is undefined
    return this->_state;
}