#include <iostream>

#include "Piece.hpp"

Piece::Piece(const std::string& nom, double prix, int quantite_depot)
    : Produit(nom, prix), _quantite_depot(quantite_depot) {}

void Piece::ajouter_piece_depot(int quantite) { _quantite_depot += quantite; }

void Piece::soustraire_piece_depot(int quantite) {
  if (quantite > _quantite_depot)
    throw std::runtime_error("Quantité insuffisante en dépôt");
  _quantite_depot -= quantite;
}

void Piece::afficher() const {
  std::cout << "Pièce : " << get_nom() << ", $ " << get_prix()
            << ", En dépôt : " << _quantite_depot << std::endl;
}

double Piece::calculer_prix() const { return get_prix(); }

char Piece::get_type_produit() const { return 'P'; }

int Piece::get_quantite_depot() const { return _quantite_depot; }