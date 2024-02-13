#include "Errors.hpp"

FactureFinaliseeException::FactureFinaliseeException(const std::string &message)
    : _message(message) {}

const char *FactureFinaliseeException::what() const throw() {
  return _message.c_str();
}

FacturePasFinaliseeException::FacturePasFinaliseeException(
    const std::string &message)
    : _message(message) {}

const char *FacturePasFinaliseeException::what() const throw() {
  return "La facture doit être finalisée avant le registre";
}