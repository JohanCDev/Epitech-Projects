/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Loop
*/

#include "Loop.hpp"

#include <exception>
#include <iostream>
#include <algorithm>


nts::Loop::Loop() {
}

void nts::Loop::createMap() {
    this->_mapCommands[std::string("simulate")] = [this](std::string const &args) { this->simulate_all(args); };
    this->_mapCommands[std::string("loop")] = [this](std::string const &args) { this->loop(args); };
    this->_mapCommands[std::string("exit")] = [this](std::string const &args) { this->exit(args); };
    this->_mapCommands[std::string("display")] = [this](std::string const &args) { this->dump_all(args); };
    this->_mapCommands[std::string("clear")] = [this](std::string const &args) { this->clear_term(args); };
    this->_mapCommands[std::string("dump")] = [this](std::string const &args) {this->my_dump(args); };
}

nts::Tristate nts::Loop::convertState(const std::string &stringState)
{
    if (stringState == "1")
        return nts::TRUE;
    else
        return nts::FALSE;
}

void nts::Loop::input(std::string const &inputName, std::string const &args)
{
    if (args.empty())
        return;
    if (args != "0" && args != "1") {
        std::cerr << "Invalid args given" << std::endl;
        return;
    }

    for (size_t x = 0; x < this->_pins.size(); x++) {
        if (_pins[x].get()->getName() == inputName) {
            _pins[x].get()->setState(convertState(args));
            return;
        }
    }
    std::cerr << "Component not found" << std::endl;
}

void nts::Loop::simulate_all(std::string const &args) {
    if (!args.empty())
        return;
    nts::Tristate tmp;
    for (size_t x = 0; x < this->_pins.size(); x++) {
        tmp = this->_pins[x].get()->compute();
        this->_pins[x].get()->setState(tmp);
    }
}

void nts::Loop::loop(std::string const &args) {
    if (!args.empty())
        return;
    std::cout << "loop" << std::endl;
}

void nts::Loop::dump_all(std::string const &args) {
    if (!args.empty())
        return;
    std::cout << "tick:" << this->getTick() << std::endl;
    //std::sort(this->_pins.begin(), this->_pins.end(), &compareFunction);
    std::cout << "input(s):" << std::endl;
    for (size_t x = 0; x < this->_pins.size(); x++) {
        if (this->_pins[x].get()->getUse() == INPUT)
            std::cout << "\t" << this->_pins[x].get()->getName() << ": " << (this->_pins[x].get()->getState() == 1 ? 1 : 0) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (size_t x = 0; x < this->_pins.size(); x++) {
        if (this->_pins[x].get()->getUse() == OUTPUT)
            std::cout << "\t" << this->_pins[x].get()->getName() << ": " << (this->_pins[x].get()->getState() == 1 ? 1 : 0) << std::endl;
    }
}

void nts::Loop::my_dump(std::string const &args)
{
    for (size_t x = 0; x < this->_pins.size(); x++) {
        this->_pins[x].get()->dump();
    }
    std::cout << "tick count = " << this->getTick() << std::endl;
}

void nts::Loop::clear_term(std::string const &args) {
    if (!args.empty())
        return;
    std::cout << "\e[1;1H\e[2J" << std::endl;
}

void nts::Loop::exit(std::string const &args) {
    if (!args.empty())
        return;
    std::cout << "exit" << std::endl;
    std::exit(0);
}

void nts::Loop::computeAll(void) {
    this->createMap();
    while (1) {
        std::cout << "> ";
        if (!std::getline(std::cin, this->_line))
            break;
        const unsigned long indexSplit = this->_line.find_first_of("=");
        std::string command = this->_line.substr(0, indexSplit);
        std::string args("");
        if (indexSplit != std::string::npos)
            args = this->_line.substr(indexSplit + 1, this->_line.length());
        if (this->_mapCommands.count(command) != 0) {
            this->_mapCommands[command](args);
        } else if (indexSplit != std::string::npos) {
            // Input change handling
            this->input(command, args);
        } else {
            std::cerr << this->_line << ": unknown command" << std::endl;
        }
    }
}

nts::Tristate nts::Loop::compute() {
    return nts::Tristate::TRUE;
}