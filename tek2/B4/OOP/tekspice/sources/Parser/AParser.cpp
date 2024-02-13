/*
** EPITECH PROJECT, 2022
** tekSpice
** File description:
** AParser
*/

#include "AParser.hpp"

#include <fstream>

#include "Error/ParserError.hpp"

nts::Parser::AParser::AParser(std::string const &filename) : _filename(filename) {
    this->_content = "";
    this->_fileIsRetrieved = false;
}

nts::Parser::AParser::~AParser() {
}

void nts::Parser::AParser::retrieveInfoFromFile(void) {
    std::ifstream myFile;
    myFile.open(this->_filename);
    if (!myFile.is_open())
        throw nts::Parser::error::FileNotOpened("File couldn't be opened");
    std::getline(myFile, this->_content, '\0');
    myFile.close();
    this->_fileIsRetrieved = true;
}

const std::string &nts::Parser::AParser::getContent(void) const {
    return this->_content;
}

const bool &nts::Parser::AParser::getFileIsRetrieved(void) const {
    return this->_fileIsRetrieved;
}