/*
** EPITECH PROJECT, 2022
** tekSpice
** File description:
** NTSParser
*/

#ifndef NTSPARSER_HPP_
#define NTSPARSER_HPP_

#include <functional>
#include <map>
#include <string>

#include "AComponent.hpp"
#include "AParser.hpp"
#include "Loop.hpp"

namespace nts::Parser {
class NTSParser : public nts::Parser::AParser {
   public:
    NTSParser(const std::string &filename = "");
    ~NTSParser() = default;
    std::unique_ptr<nts::Loop> parseFile(void);

   protected:
   private:
    std::unique_ptr<nts::Loop> calculatePins(void);
    void checkLinksName(void);

    std::string _linksInfos;
    std::string _chipsetsInfos;
    size_t nbInputs;
    size_t nbOutputs;
};
}  // namespace nts::Parser

#endif /* !NTSPARSER_HPP_ */
