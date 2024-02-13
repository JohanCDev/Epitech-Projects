/*
** EPITECH PROJECT, 2022
** tekSpice
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>

namespace nts::Parser {
class IParser {
   public:
    virtual ~IParser() = default;
    virtual const std::string &getContent(void) const = 0;
    virtual void retrieveInfoFromFile(void) = 0;
    virtual const bool &getFileIsRetrieved(void) const = 0;

   protected:
   private:
};
}  // namespace nts::Parser

#endif /* !PARSER_HPP_ */
