/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** component4069
*/

#ifndef COMPONENT4069_HPP_
#define COMPONENT4069_HPP_

#include "ComponentList.hpp"
#include "InverterGates.hpp"

namespace nts
{

    class Component4069 : public AComponent
    {
        public:
            Component4069(const std::string &name = "4069");
            ~Component4069() = default;

            nts ::Tristate compute();
        protected:

        private:
            std::vector<InverterGates> _gates;
            std::vector<Electrical> _unusedPins;
    };
}

#endif /* !COMPONENT4069_HPP_ */
