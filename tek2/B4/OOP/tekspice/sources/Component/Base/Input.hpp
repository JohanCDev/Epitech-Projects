/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "AComponent.hpp"

namespace nts
{
    class Input : public AComponent
    {
    public:
        Input(const std::string &name = "Input", nts::Tristate state = UNDEFINED);
        ~Input() = default;


        nts ::Tristate compute();
    protected:
    private:
    };
}

#endif /* !INPUT_HPP_ */
