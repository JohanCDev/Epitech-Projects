/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <memory>
#include <string>
#include <vector>

#include "IComponent.hpp"

namespace nts
{
    enum Usestate
    {
        ELECTRICAL = -1,
        COMPONENT,
        INPUT,
        OUTPUT,
    };

    enum Components
    {
        ROM = 2716,
        NOR = 4001,
        ADDER = 4008,
        NAND = 4011,
        FLIPFLOP = 4013,
        JOHNSON = 4017,
        XOR = 4030,
        COUNTER = 4040,
        NOT = 4069,
        OR = 4071,
        AND = 4081,
        SHIFT = 4094,
        SELECTOR = 4512,
        RAM = 4801,
        FALSE_COMP = 0,
        TRUE_COMP = 1,
        CLOCK = 2,
        INPUTOUTPUT = 3,
        LOGGER = 4,
        ALTEREDCOUNTER = 5,
        ANDORNOT = 6,
        AND_ADVANCED = 7
    };

    class AComponent : public IComponent
    {
    public:
        AComponent(const std::string &name, Usestate use = COMPONENT, Tristate state = UNDEFINED);

        virtual ~AComponent() = default;

        void simulate(size_t tick);
        void setLink(size_t pin, nts::IComponent &other, size_t otherPin);
        void dump() const;

        void setState(nts::Tristate newState);
        nts::Tristate getState(void) const;
        nts::Usestate getUse(void) const;
        const std::string &getName(void) const;

        std::shared_ptr<AComponent> getPin(size_t pin) const;

    protected:
        std::string _name;
        nts::Usestate _use;
        nts::Tristate _state;

        std::vector<std::shared_ptr<AComponent>> _pins;
        std::vector<std::shared_ptr<AComponent>> _preceding;

    private:
        bool usable(Usestate use);
        std::string getStrUse(void) const;
        std::string getStrState(void) const;
    };
} // namespace nts

#endif /* !ACOMPONENT_HPP_ */
