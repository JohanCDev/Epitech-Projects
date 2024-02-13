#include <iostream>
#include <string>

#include "Vehicle.hpp"

int Vehicle::_id_suivant = 0;

Vehicle::Vehicle(const std::string& plaque, const std::string& modele,
                 const std::string& annee, const std::string& type)
    : _plaque(plaque), _modele(modele), _annee(annee), _type(type) {
  _id = _id_suivant++;
}

int Vehicle::get_id() const { return _id; }

int Vehicle::get_id_suivant() const { return _id_suivant; }

const std::string& Vehicle::get_plaque() const { return _plaque; }

const std::string& Vehicle::get_modele() const { return _modele; }

const std::string& Vehicle::get_annee() const { return _annee; }

const std::string& Vehicle::get_type() const { return _type; }

void Vehicle::set_id_suivant(int id_suivant) { _id_suivant = id_suivant; }