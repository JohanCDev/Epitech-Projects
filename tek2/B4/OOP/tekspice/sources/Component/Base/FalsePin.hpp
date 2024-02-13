/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** FalsePin
*/

#ifndef FALSEPIN_HPP_
#define FALSEPIN_HPP_

#include "AComponent.hpp"

namespace nts
{

    class FalsePin : public AComponent
    {
    public:
        FalsePin(const std::string &name = "FalsePin");
        ~FalsePin() = default;

        nts::Tristate compute();
    protected:
    private:
    };
}

#endif /* !FALSEPIN_HPP_ */
