/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** NandGates
*/

#ifndef NANDGATES_HPP_
#define NANDGATES_HPP_

#include "../ComponentList.hpp"

namespace nts
{

    class NandGates : public AComponent
    {
    public:
        NandGates(const std::string &name = "Nand Gates");
        ~NandGates() = default;

        nts ::Tristate compute();
    protected:
    private:
    };
}

#endif /* !NANDGATES_HPP_ */
