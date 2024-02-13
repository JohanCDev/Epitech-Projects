/*
** EPITECH PROJECT, 2022
** tekSpice
** File description:
** AParser
*/

#ifndef APARSER_HPP_
#define APARSER_HPP_

#include "IParser.hpp"

namespace nts::Parser {
class AParser : public nts::Parser::IParser {
   public:
    AParser(std::string const &filename = "");
    ~AParser() override;
    const std::string &getContent(void) const override;
    void retrieveInfoFromFile(void) override;
    const bool &getFileIsRetrieved(void) const override;

   protected:
    const std::string _filename;
    std::string _content;

   private:
    bool _fileIsRetrieved;
};
}  // namespace nts::Parser

#endif /* !APARSER_HPP_ */
