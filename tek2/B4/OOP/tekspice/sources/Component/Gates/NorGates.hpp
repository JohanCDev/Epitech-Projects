/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** NorGates
*/

#ifndef NORGATES_HPP_
#define NORGATES_HPP_

#include "../ComponentList.hpp"

namespace nts
{

    class NorGates : public AComponent
    {
    public:
        NorGates(const std::string &name = "NorGates");
        ~NorGates() = default;

        nts ::Tristate compute();
    protected:
    private:
    };
}

#endif /* !NORGATES_HPP_ */
