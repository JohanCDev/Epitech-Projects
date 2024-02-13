#include <iostream>
#include <memory>

#include "Client.hpp"
#include "Facture.hpp"
#include "Piece.hpp"
#include "ProduitFacture.hpp"
#include "Service.hpp"
#include "Vehicle.hpp"

int main() {
  std::cout << "**** Pieces et service ****" << std::endl;
  Piece *piece = new Piece("Piece", 10.0, 10);
  Service *service = new Service("Service", 20.0, 3);

  // Ajout de plus de pièces et de services
  Piece *piece2 = new Piece("Piece2", 20.0, 20);
  Service *service2 = new Service("Service2", 30.0, 4);
  Piece *piece3 = new Piece("Piece3", 40.0, 30);
  Service *service3 = new Service("Service3", 50.0, 5);

  piece->afficher();
  service->afficher();
  piece2->afficher();
  service2->afficher();
  piece3->afficher();
  service3->afficher();

  // Ajouter les appels de fonction pour les autres méthodes de Piece et Service

  piece->ajouter_piece_depot(5);
  piece2->soustraire_piece_depot(5);
  service->afficher();
  piece->afficher();
  std::cout << piece->get_nom() << " " << piece->get_prix() << " "
            << piece->get_quantite_depot() << std::endl;
  std::cout << service->get_nom() << " " << service->get_prix() << " "
            << service->get_description() << " " << service->get_type_produit()
            << std::endl;
  service->set_description("Nouvelle description");

  std::cout << "\n**** ProduitFacture ****" << std::endl;
  ProduitFacture *pfacture = new ProduitFacture(piece, 6);
  pfacture->afficher_produit();
  std::cout << *pfacture << std::endl;

  ProduitFacture *pfacture2 = new ProduitFacture(piece2, 7);
  pfacture2->afficher_produit();
  std::cout << *pfacture2 << std::endl;

  ProduitFacture *pfacture3 = new ProduitFacture(piece3, 8);
  pfacture3->afficher_produit();
  std::cout << *pfacture3 << std::endl;

  std::cout << "\n**** Clients et véhicules ****" << std::endl;
  Client *client = new Client("Eduardo", "Rue X", "666 666-66-66");
  Vehicle *vehicle = new Vehicle("JHJ 233", "Honda", "2020", "Voiture");

  // Création de plus de clients et de véhicules

  Client *client2 = new Client("Eduardo2", "Rue X2", "666 666-66-66");
  Vehicle *vehicle2 = new Vehicle("POP 233", "Honda2", "2020", "Voiture2");

  std::cout << client->get_id() << client->get_nom() << client->get_adresse()
            << client->get_phone() << std::endl;
  std::cout << vehicle->get_id() << vehicle->get_modele()
            << vehicle->get_annee() << vehicle->get_type()
            << vehicle->get_plaque() << std::endl;

  std::cout << "\n**** Factures ****" << std::endl;
  Facture *facture = new Facture(client, "2020-10-10");

  facture->set_client(client);
  facture->set_vehicle(vehicle);

  // Utilisation des autres constructeurs de Facture

  Facture *facture2 = new Facture(client2, vehicle2, "2020-10-10");
  Facture *facture3 = new Facture("2020-10-10");

  std::cout << "\n**** Ajout des produits à la facture ****" << std::endl;
  facture->ajouter_produit(pfacture);
  facture->ajouter_produit(service, 5);

  std::cout << "\n**** Affichage de la facture ****" << std::endl;
  facture->afficher_facture();

  std::cout << "\n**** Factures: scénarios d'exception ****" << std::endl;

  std::cout << "\n\t* Enregistrer une facture finalisée *" << std::endl;

  try {
    facture->enregistrer_facture();
  } catch (const std::exception &e) {
    std::cerr << "\t\tException: " << e.what() << std::endl;
  }

  facture->finaliser_facture();
  std::cout << "\n\t* Pas assez de produits en dépôt *" << std::endl;

  ProduitFacture *pfactureFail = new ProduitFacture(piece, 100);
  Facture *factureFail = new Facture(client, "2020-10-10");
  try {
    factureFail->ajouter_produit(pfactureFail);
    factureFail->finaliser_facture();
  } catch (const std::runtime_error &e) {
    std::cerr << "\t\tException: " << e.what() << std::endl;
  }

  std::cout << "\n\t* Modifier une facture finalisée *" << std::endl;

  try {
    facture->ajouter_produit(piece, 1);
  } catch (const std::exception &e) {
    std::cerr << "\t\tException: " << e.what() << std::endl;
  }

  delete piece;
  delete piece2;
  delete piece3;
  delete service;
  delete service2;
  delete service3;
  delete pfacture;
  delete pfacture2;
  delete pfacture3;
  delete client;
  delete client2;
  delete vehicle;
  delete vehicle2;
  delete facture;
  delete facture2;
  delete facture3;
  delete factureFail;
  delete pfactureFail;

  return 0;
}
