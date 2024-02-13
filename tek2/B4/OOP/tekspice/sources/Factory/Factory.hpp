/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_
#include <functional>
#include <map>
#include <memory>

#include "../Component/AComponent.hpp"
#include "../Component/Base/Clock.hpp"
#include "../Component/Base/FalsePin.hpp"
#include "../Component/Base/TruePin.hpp"
#include "../Component/Gates/AndGates.hpp"
#include "../Component/Gates/InverterGates.hpp"
#include "../Component/Gates/NandGates.hpp"
#include "../Component/Gates/NorGates.hpp"
#include "../Component/Gates/OrGates.hpp"
#include "../Component/Gates/XorGates.hpp"

namespace nts {
class Factory {
   public:
    Factory();
    ~Factory() = default;
    void createMap();
    std::map<std::string, std::function<std::shared_ptr<nts::AComponent>(std::string const &name, nts::Circuit)>> getMap();

   protected:
   private:
    std::shared_ptr<nts::AndGates> createAndGate(std::string const &name, nts::Circuit);
    std::shared_ptr<nts::InverterGates> createInverterGate(std::string const &name, nts::Circuit);
    std::shared_ptr<nts::NandGates> createNandGate(std::string const &name, nts::Circuit);
    std::shared_ptr<nts::NorGates> createNorGate(std::string const &name, nts::Circuit);
    std::shared_ptr<nts::OrGates> createOrGate(std::string const &name, nts::Circuit);
    std::shared_ptr<nts::XorGates> createXorGate(std::string const &name, nts::Circuit);
    std::shared_ptr<nts::Input> createInput(std::string const &name, nts::Circuit);
    std::shared_ptr<nts::Output> createOutput(std::string const &name, nts::Circuit);
    std::shared_ptr<nts::TruePin> createTrue(std::string const &name, nts::Circuit);
    std::shared_ptr<nts::FalsePin> createFalse(std::string const &name, nts::Circuit);
    // std::unique_ptr<nts::Clock> createClock(std::string const &name); // TODO Implement it before
    std::map<std::string, std::function<std::shared_ptr<nts::AComponent>(std::string const &name, nts::Circuit)>> _creatorMap;
};
}  // namespace nts

#endif /* !FACTORY_HPP_ */
