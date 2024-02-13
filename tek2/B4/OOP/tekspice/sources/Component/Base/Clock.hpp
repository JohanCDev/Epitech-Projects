/*
** EPITECH PROJECT, 2022
** NTS
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "../../Circuit/Circuit.hpp"
#include "../AComponent.hpp"

namespace nts {

class Clock : public AComponent {
   public:
    Clock(nts::Tristate state = UNDEFINED, const std::string &name = "Clock");
    ~Clock() = default;

    nts::Tristate compute();

   protected:
   private:
};

}  // namespace nts

#endif /* !CLOCK_HPP_ */
