/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** component4011
*/

#ifndef COMPONENT4011_HPP_
#define COMPONENT4011_HPP_

#include "ComponentList.hpp"
#include "NandGates.hpp"

namespace nts
{

    class Component4011 : public AComponent
    {
        public:
            Component4011(const std::string &name = "4011");
            ~Component4011() = default;

            nts ::Tristate compute();
        protected:

        private:
            std::vector<NandGates> _gates;
            std::vector<Electrical> _unusedPins;
    };

}

#endif /* !COMPONENT4011_HPP_ */
