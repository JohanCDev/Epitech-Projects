/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** InverterGates
*/

#ifndef INVERTERGATES_HPP_
#define INVERTERGATES_HPP_

#include "../ComponentList.hpp"

namespace nts
{

    class InverterGates : public AComponent
    {
    public:
        InverterGates(const std::string &name = "Inverter Gate");
        ~InverterGates() = default;

        nts ::Tristate compute();
    protected:
    private:
    };

}
#endif /* !INVERTERGATES_HPP_ */
