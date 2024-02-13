/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** XorGates
*/

#ifndef XORGATES_HPP_
#define XORGATES_HPP_

#include "../ComponentList.hpp"

namespace nts
{

    class XorGates : public AComponent
    {
    public:
        XorGates(const std::string &name = "Xor Gates");
        ~XorGates() = default;

        nts ::Tristate compute();
    protected:
    private:
    };
}

#endif /* !XORGATES_HPP_ */
