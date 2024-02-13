/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "AComponent.hpp"

namespace nts
{
    class TruePin : public AComponent
    {
    public:
        TruePin(const std::string &name = "TruePin");
        ~TruePin() = default;

        nts ::Tristate compute();
    protected:
    private:
    };
}

#endif /* !TRUE_HPP_ */
