/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** component4030
*/

#ifndef COMPONENT4030_HPP_
#define COMPONENT4030_HPP_

#include "ComponentList.hpp"
#include "OrGates.hpp"

namespace nts
{

    class Component4030 : public AComponent
    {
        public:
            Component4030(const std::string &name = "4030");
            ~Component4030() = default;

            nts ::Tristate compute();
        protected:

        private:
            std::vector<OrGates> _gates;
            std::vector<Electrical> _unusedPins;
    };

}

#endif /* !COMPONENT4030_HPP_ */
