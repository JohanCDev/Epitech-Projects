/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** Electrical
*/

#ifndef ELECTRICAL_HPP_
#define ELECTRICAL_HPP_

#include "AComponent.hpp"

namespace nts
{

    class Electrical : public AComponent
    {
    public:
        Electrical(const std::string &name = "Electrical");
        ~Electrical() = default;

        nts::Tristate compute();

    protected:
    private:
    };
}
#endif /* !ELECTRICAL_HPP_ */
