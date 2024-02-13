/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** AndGates
*/

#ifndef ANDGATES_HPP_
#define ANDGATES_HPP_

#include "../ComponentList.hpp"

namespace nts
{

    class AndGates : public AComponent
    {
    public:
        AndGates(const std::string &name = "AndGates");
        ~AndGates() = default;

        nts ::Tristate compute();
    protected:
    private:
    };

}

#endif /* !ANDGATES_HPP_ */
