/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <memory>
#include <vector>

#include "../Component/AComponent.hpp"

namespace nts {

class Circuit : public AComponent {
   public:
    Circuit();
    Circuit(const nts::Circuit &);
    ~Circuit();
    const nts::Circuit &operator=(const nts::Circuit &);

    void update_all(void);
    size_t getTick(void) const;
    void incrementTick(void);
    nts::Tristate compute();
    bool addComponent(std::shared_ptr<AComponent>);
    size_t getCircuitSize(void) const;

   protected:
   private:
    size_t _tick;
};
}  // namespace nts

#endif /* !CIRCUIT_HPP_ */