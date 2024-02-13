#include "Produit.hpp"

int Produit::_produit_id_suivant = 0;

Produit::Produit(const std::string& nom, double prix) : _nom(nom), _prix(prix) {
  _id = _produit_id_suivant++;
}

double Produit::get_prix() const { return _prix; }

const std::string& Produit::get_nom() const { return _nom; }