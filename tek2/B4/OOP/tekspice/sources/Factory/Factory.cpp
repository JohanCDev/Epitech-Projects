/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Factory
*/

#include "Factory.hpp"

nts::Factory::Factory() {
}

void nts::Factory::createMap() {
    this->_creatorMap[std::string("4081")] = [this](std::string const &args, nts::Circuit circuit) { return this->createAndGate(args, circuit); };
    // this->_creatorMap[std::string("4081")] = [this](std::string const &args) { this->createInverterGate(args); }; //TODO Look at the identifier
    this->_creatorMap[std::string("4011")] = [this](std::string const &args, nts::Circuit circuit) { return this->createNandGate(args, circuit); };
    this->_creatorMap[std::string("4001")] = [this](std::string const &args, nts::Circuit circuit) { return this->createNorGate(args, circuit); };
    this->_creatorMap[std::string("4071")] = [this](std::string const &args, nts::Circuit circuit) { return this->createOrGate(args, circuit); };
    this->_creatorMap[std::string("4030")] = [this](std::string const &args, nts::Circuit circuit) { return this->createXorGate(args, circuit); };
    this->_creatorMap[std::string("input")] = [this](std::string const &args, nts::Circuit circuit) { return this->createInput(args, circuit); };
    this->_creatorMap[std::string("output")] = [this](std::string const &args, nts::Circuit circuit) { return this->createOutput(args, circuit); };
    this->_creatorMap[std::string("true")] = [this](std::string const &args, nts::Circuit circuit) { return this->createTrue(args, circuit); };
    this->_creatorMap[std::string("false")] = [this](std::string const &args, nts::Circuit circuit) { return this->createFalse(args, circuit); };
    // this->_creatorMap[std::string("clock")] = [this](std::string const &args) { this->createClock(args); }; //TODO implement it
}

std::shared_ptr<nts::AndGates> nts::Factory::createAndGate(std::string const &name, nts::Circuit) {
    (void)name;
    return std::make_unique<nts::AndGates>(name);
}

std::shared_ptr<nts::InverterGates> nts::Factory::createInverterGate(std::string const &name, nts::Circuit) {
    (void)name;
    return std::make_unique<nts::InverterGates>(name);
}

std::shared_ptr<nts::NandGates> nts::Factory::createNandGate(std::string const &name, nts::Circuit) {
    (void)name;
    return std::make_unique<nts::NandGates>(name);
}

std::shared_ptr<nts::NorGates> nts::Factory::createNorGate(std::string const &name, nts::Circuit) {
    (void)name;
    return std::make_unique<nts::NorGates>(name);
}

std::shared_ptr<nts::OrGates> nts::Factory::createOrGate(std::string const &name, nts::Circuit) {
    (void)name;
    return std::make_unique<nts::OrGates>(name);
}

std::shared_ptr<nts::XorGates> nts::Factory::createXorGate(std::string const &name, nts::Circuit) {
    (void)name;
    return std::make_unique<nts::XorGates>(name);
}

std::shared_ptr<nts::Input> nts::Factory::createInput(std::string const &name, nts::Circuit) {
    (void)name;
    return std::make_unique<nts::Input>(name);
}

std::shared_ptr<nts::Output> nts::Factory::createOutput(std::string const &name, nts::Circuit) {
    (void)name;
    return std::make_unique<nts::Output>(name);
}

std::shared_ptr<nts::TruePin> nts::Factory::createTrue(std::string const &name, nts::Circuit) {
    (void)name;
    return std::make_unique<nts::TruePin>(name);
}

std::shared_ptr<nts::FalsePin> nts::Factory::createFalse(std::string const &name, nts::Circuit) {
    (void)name;
    return std::make_unique<nts::FalsePin>(name);
}

/*
 * std::unique_ptr<nts::Clock> nts::Factory::createClock(std::string const &name) {
 *     (void)name;
 *     return std::make_unique<nts::Clock>();
 * }
 */
// TODO See how to implement Clock in map

// TODO electrical component

std::map<std::string, std::function<std::shared_ptr<nts::AComponent>(std::string const &name, nts::Circuit)>> nts::Factory::getMap() {
    return this->_creatorMap;
}
