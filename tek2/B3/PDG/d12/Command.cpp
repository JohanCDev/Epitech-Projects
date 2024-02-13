/*
** EPITECH PROJECT, 2022
** Day12
** File description:
** Command
*/

#include "Command.hpp"

Command::Command()
{
}

Command::~Command()
{
}

void Command::registerCommand(const std::string &name, const std::function<void()> &function)
{
    if (this->_map.count(name))
        throw Error("Already registered command");
    this->_map[name] = function;
}

void Command::executeCommand(const std::string& name)
{
    if (this->_map.count(name) == 0)
        throw Error("Unknow command");
    this->_map[name]();
}