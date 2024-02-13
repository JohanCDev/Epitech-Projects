/*
** EPITECH PROJECT, 2022
** tekSpice
** File description:
** NTSParser
*/

#include "NTSParser.hpp"

#include <exception>
#include <iostream>
#include <sstream>

#include "../Factory/Factory.hpp"
#include "NTSError.hpp"
#include "ParserError.hpp"

bool is_number(const std::string &s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

nts::Parser::NTSParser::NTSParser(std::string const &filename) : nts::Parser::AParser(filename) {
    this->nbInputs = 0;
    this->nbOutputs = 0;
}

void nts::Parser::NTSParser::checkLinksName(void) {
    std::stringstream ss(this->_linksInfos);
    std::string line;
    std::string init;
    std::string comp;
    while (getline(ss, line, '\n')) {
        if (line.at(0) == '#')
            continue;
        (std::stringstream) line >> init;
        (std::stringstream) & line[init.length()] >> comp;
        if (init.find(":") == std::string::npos)
            throw nts::Parser::error::InvalidLinkName("No Link initialization");
        std::string initName(init.substr(0, init.find(":")));
        if (this->_chipsetsInfos.find(initName) == std::string::npos)
            throw nts::Parser::error::InvalidLinkName("Invalid link name");
        std::string initNumber(init.substr(init.find(":") + 1));
        if (!is_number(initNumber))
            throw nts::Parser::error::InvalidLinkName("Link value is not a number");
        if (comp.find(":") == std::string::npos)
            throw nts::Parser::error::InvalidLinkName("No initialization");
        std::string compName(comp.substr(0, comp.find(":")));
        if (this->_chipsetsInfos.find(compName) == std::string::npos)
            throw nts::Parser::error::InvalidLinkName("Invalid link name");
        std::string compNumber(comp.substr(comp.find(":") + 1));
        if (!is_number(compNumber))
            throw nts::Parser::error::InvalidLinkName("Link value is not a number");
    }
}

std::unique_ptr<nts::Loop> nts::Parser::NTSParser::calculatePins(void) {
    std::stringstream ss(this->_chipsetsInfos);
    std::string line;
    std::string init;
    std::string comp;
    nts::Factory facto;
    nts::Loop mainLoop;
    facto.createMap();
    std::map<std::string, std::function<std::shared_ptr<nts::AComponent>(std::string const &name, nts::Circuit circuit)>> creatorMap = facto.getMap();
    while (getline(ss, line, '\n')) {
        // TODO Comments gesture
        if (line.at(0) == '#')
            continue;
        (std::stringstream) line >> init;
        (std::stringstream) & line[init.length()] >> comp;
        if (init == "input" || init == "clock" || init == "true" || init == "false")
            this->nbInputs++;
        else if (init == "output")
            this->nbOutputs++;
        if (creatorMap.count(init) == 0)
            throw nts::Parser::error::BadFormat("Invalid input name");
        else
            mainLoop.addComponent(creatorMap[init](comp, mainLoop));
    }
    return std::make_unique<Loop>(mainLoop);
}

std::unique_ptr<nts::Loop> nts::Parser::NTSParser::parseFile(void) {
    if (this->getFileIsRetrieved() == false)
        throw nts::Parser::error::EmptyFileContent("File hasn't been retrieved");
    size_t idxFirstChip = this->_content.find(".chipsets:\n");
    size_t idxFirstLinks = this->_content.find(".links:\n");

    if (idxFirstChip == std::string::npos || idxFirstLinks == std::string::npos)
        throw nts::Parser::error::BadFormat("Missing informations");
    this->_chipsetsInfos = this->_content.substr(idxFirstChip + std::string(".chipsets:\n").length(), idxFirstLinks - (idxFirstChip + std::string(".chipsets:\n").length()) - 1);
    this->_linksInfos = this->_content.substr(idxFirstLinks + std::string(".links:\n").length(), this->_content.length() - (idxFirstLinks + std::string(".links:\n").length()));

    std::unique_ptr<nts::Loop> mainLoop;

    try {
        mainLoop = this->calculatePins();
        this->checkLinksName();
    } catch (nts::Parser::error::ParserError &e) {
        throw nts::Parser::error::ParserError(e.what());
    }
    return mainLoop;
}