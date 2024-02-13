/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** main
*/

#include <string.h>

#include <iostream>

#include "Component/ComponentList.hpp"
#include "Component/Gates/AndGates.hpp"
#include "Loop/Loop.hpp"
#include "Parser/Error/NTSError.hpp"
#include "Parser/Error/ParserError.hpp"
#include "Parser/NTSParser.hpp"

void displayHelper() {
    std::cout << "USAGE:\n\t./nanotekspice <file>" << std::endl;
}

int main(int ac, char **av) {
    if (ac != 2)
        return 84;
    if (!strcmp("-h", av[1])) {
        displayHelper();
        return 0;
    }
    nts::Parser::NTSParser parser(av[1]);

    std::unique_ptr<nts::Loop> mainLoop;
    try {
        parser.retrieveInfoFromFile();
        mainLoop = parser.parseFile();
    } catch (nts::Parser::error::ParserError &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (std::exception &e) {
        std::cerr << "Not supposed to happen: " << e.what() << std::endl;
        return 84;
    }
    mainLoop.get()->computeAll();
    // if (parser.getMap().count(nts::AND) != 0) {
    //     parser.getMap()[nts::AND]("and");
    // }
    // Example to call an element of the map
}
