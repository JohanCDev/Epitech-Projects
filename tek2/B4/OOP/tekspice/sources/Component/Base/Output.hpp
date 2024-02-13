/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "AComponent.hpp"

namespace nts
{

    class Output : public AComponent
    {
    public:
        Output(const std::string &name = "Output", nts::Tristate state = UNDEFINED);
        ~Output() = default;

        nts ::Tristate compute();
    protected:
    private:
    };
}

#endif /* !OUTPUT_HPP_ */
