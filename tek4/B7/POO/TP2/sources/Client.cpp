#include "Client.hpp"

int Client::_client_id_suivant = 0;

Client::Client(const std::string& nom, const std::string& adresse,
               const std::string& phone)
    : _nom(nom), _adresse(adresse), _phone(phone) {
  _id = _client_id_suivant++;
}

int Client::get_id() const { return _id; }

int Client::get_id_suivant() const { return _client_id_suivant; }

const std::string& Client::get_nom() const { return _nom; }

const std::string& Client::get_adresse() const { return _adresse; }

const std::string& Client::get_phone() const { return _phone; }