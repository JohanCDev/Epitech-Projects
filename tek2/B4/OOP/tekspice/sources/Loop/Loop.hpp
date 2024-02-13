/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Loop
*/

#ifndef LOOP_HPP_
#define LOOP_HPP_

#include <functional>
#include <map>
#include <string>

#include "Circuit.hpp"
#include "IComponent.hpp"

namespace nts {
class Loop : public Circuit {
   public:
    Loop();
    ~Loop() = default;
    void computeAll(void);
    void simulate_all(std::string const &);
    void dump_all(std::string const &);
    void my_dump(std::string const &);
    void exit(std::string const &);
    void display(std::string const &);
    void input(std::string const &, std::string const &);
    void loop(std::string const &);
    void clear_term(std::string const &);
    nts::Tristate compute();

   protected:
   private:
    void createMap();
    nts::Tristate convertState(const std::string &stringState);
    std::string _line;
    std::map<std::string, std::function<void(std::string const &args)>> _mapCommands;
};
}  // namespace nts

#endif /* !LOOP_HPP_ */
