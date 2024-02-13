/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** component4081
*/

#ifndef COMPONENT4081_HPP_
#define COMPONENT4081_HPP_

#include "ComponentList.hpp"
#include "AndGates.hpp"

namespace nts
{

    class Component4081 : public AComponent
    {
        public:
            Component4081(const std::string &name = "4081");
            ~Component4081() = default;

            nts ::Tristate compute();
        protected:

        private:
            std::vector<AndGates> _gates;
            std::vector<Electrical> _unusedPins;
    };

}

#endif /* !COMPONENT4081_HPP_ */
