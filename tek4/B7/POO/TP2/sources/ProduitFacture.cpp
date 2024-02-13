#include <iostream>

#include "Produit.hpp"
#include "ProduitFacture.hpp"

int ProduitFacture::_id_suivant = 0;

ProduitFacture::ProduitFacture(Produit* produit, int quantite)
    : _quantite(quantite), _produit(produit) {
  _id = _id_suivant++;
  _prix_total = _produit->calculer_prix() * _quantite;
}

void ProduitFacture::afficher_produit() const {
  std::cout << "Qté : " << _quantite << ", Produit/Service : ("
            << _produit->get_type_produit()
            << "), Unitaire : " << _produit->get_prix()
            << ", Total : " << _prix_total << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ProduitFacture& pfacture) {
  os << pfacture.get_quantite() << "\t| ";
  if (pfacture.get_produit()->get_type_produit() == 'P')
    os << "Pièce\t\t\t(P)";
  else
    os << "Service\t\t(S)";
  os << "| " << pfacture.get_produit()->get_prix() << "\t\t| "
     << pfacture.get_prix_total() << std::endl;
  return os;
}

void ProduitFacture::set_quantite(int quantite) {
  _quantite = quantite;
  _prix_total = _produit->calculer_prix() * _quantite;
}

Produit* ProduitFacture::get_produit() const { return _produit; }

int ProduitFacture::get_quantite() const { return _quantite; }

double ProduitFacture::get_prix_total() const { return _prix_total; }