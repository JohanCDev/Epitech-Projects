#include <fstream>
#include <memory>
#include <vector>

#include "Client.hpp"
#include "Errors.hpp"
#include "Facture.hpp"
#include "Piece.hpp"
#include "Produit.hpp"
#include "ProduitFacture.hpp"
#include "Vehicle.hpp"

int Facture::_facture_id_suivant = 0;

Facture::Facture(const std::string &date_facture)
    : _date_facture(date_facture) {
  _id = _facture_id_suivant++;
  _status = 0;
  _balance = 0;
}

Facture::Facture(Client *client, const std::string &date_facture)
    : Facture(date_facture) {
  _client = client;
}

Facture::Facture(Client *client, Vehicle *vehicle,
                 const std::string &date_facture)
    : Facture(date_facture) {
  _client = client;
  _vehicle = vehicle;
}

void Facture::ajouter_produit(Produit *produit, int quantite) {
  if (_status == 1)
    throw FactureFinaliseeException("La facture a déjà été finalisée");
  _produits.push_back(ProduitFacture(produit, quantite));
}

void Facture::ajouter_produit(ProduitFacture *produit_facture) {
  if (_status == 1)
    throw FactureFinaliseeException("La facture a déjà été finalisée");
  _produits.push_back(*produit_facture);
}

void Facture::afficher_facture() const { afficher_facture(std::cout); }

void Facture::afficher_facture(std::ostream &os) const {
  os << "-------------------------------------------------------" << std::endl;
  os << "                       FACTURE" << std::endl;
  os << "-------------------------------------------------------" << std::endl;
  os << "Client : " << _client->get_nom() << std::endl;
  os << "Adresse : " << _client->get_adresse() << std::endl;
  os << "Phone : " << _client->get_phone() << std::endl;
  os << "Vehicule : " << _vehicle->get_modele()
     << "| Plaque: " << _vehicle->get_plaque() << std::endl;
  os << "-------------------------------------------------------" << std::endl;
  os << "Qte\t| Produit / Service\t   | Unitaire\t| Total\n";
  for (const ProduitFacture &produit : _produits) {
    os << produit;
  }
  os << "-------------------------------------------------------" << std::endl;
  os << "\t\t\t\t\t Balance| " << this->calculer_balance() << "" << std::endl;
}

double Facture::calculer_balance() const {
  double balance = 0;
  for (auto &produit : _produits) {
    balance += produit.get_prix_total();
  }
  return balance;
}

void Facture::finaliser_facture() {
  if (_status == 1)
    throw FactureFinaliseeException("La facture a déjà été finalisée");
  _balance = calculer_balance();
  _status = 1;
  for (auto &produit : _produits) {
    if (produit.get_produit()->get_type_produit() == 'P') {
      Piece *piece_produit = dynamic_cast<Piece *>(produit.get_produit());

      if (piece_produit != nullptr) {
        piece_produit->soustraire_piece_depot(produit.get_quantite());
      }
    }
  }
}

void Facture::enregistrer_facture() const {
  if (_status == 0)
    throw FacturePasFinaliseeException(
        "La facture doit être finalisée avant le registre");
  std::ofstream fichier("facture_" + std::to_string(_id) + ".txt");
  afficher_facture(fichier);
  fichier.close();
}

void Facture::set_client(Client *client) {
  if (_status == 1)
    throw FactureFinaliseeException("La facture a déjà été finalisée");
  _client = client;
}

void Facture::set_vehicle(Vehicle *vehicle) {
  if (_status == 1)
    throw FactureFinaliseeException("La facture a déjà été finalisée");
  _vehicle = vehicle;
}