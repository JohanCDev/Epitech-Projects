/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** OrGates
*/

#ifndef ORGATES_HPP_
#define ORGATES_HPP_

#include "../ComponentList.hpp"

namespace nts
{

    class OrGates : public AComponent
    {
    public:
        OrGates(const std::string &name = "Or Gates");
        ~OrGates() = default;

        nts::Tristate compute();
    protected:
    private:
    };

}

#endif /* !ORGATES_HPP_ */
