/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** component4071
*/

#ifndef COMPONENT4071_HPP_
#define COMPONENT4071_HPP_

#include "ComponentList.hpp"
#include "OrGates.hpp"

namespace nts
{

    class Component4071 : public AComponent
    {
        public:
            Component4071(const std::string &name = "4071");
            ~Component4071() = default;

            nts ::Tristate compute();
        protected:

        private:
            std::vector<OrGates> _gates;
            std::vector<Electrical> _unusedPins;
    };

}

#endif /* !COMPONENT4071_HPP_ */
