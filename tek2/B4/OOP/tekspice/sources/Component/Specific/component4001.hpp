/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** component4001
*/

#ifndef COMPONENT4001_HPP_
#define COMPONENT4001_HPP_

#include "ComponentList.hpp"
#include "NorGates.hpp"

namespace nts
{

    class Component4001 : public AComponent
    {
        public:
            Component4001(const std::string &name = "4001");
            ~Component4001() = default;

            nts ::Tristate compute();
        protected:

        private:
            std::vector<NorGates> _gates;
            std::vector<Electrical> _unusedPins;
    };

}


#endif /* !COMPONENT4001_HPP_ */
