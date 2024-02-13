#ifndef __FACTURE_HPP__
#define __FACTURE_HPP__

#include <fstream>

#include "Client.hpp"
#include "Produit.hpp"
#include "ProduitFacture.hpp"
#include "Vehicle.hpp"

/**
 * @brief Classe Facture
 * @details This class is used to represent a facture
 */
class Facture {
 public:
  /**
   * @brief Construct a new Facture object
   * @param date_facture The date of the facture
   */
  Facture(const std::string &date_facture);

  /**
   * @brief Construct a new Facture object
   * @param client The client of the facture
   * @param date_facture The date of the facture
   * @see Client
   */
  Facture(Client *client, const std::string &date_facture);

  /**
   * @brief Construct a new Facture object
   * @param client The client of the facture
   * @param vehicle The vehicle of the facture
   * @param date_facture The date of the facture
   * @see Vehicle
   * @see Client
   */
  Facture(Client *client, Vehicle *vehicle, const std::string &date_facture);

  /**
   * @brief Adds a product to the facture by creating a ProduitFacture object
   * from provided data
   * @param produit The product to add
   * @param quantite The quantity of the product to add
   * @see ProduitFacture
   */
  void ajouter_produit(Produit *produit, int quantite);

  /**
   * @brief Adds a product to the facture
   * @param produit_facture The product to add
   * @see ProduitFacture
   */
  void ajouter_produit(ProduitFacture *produit_facture);

  /**
   * @brief Displays the facture
   */
  void afficher_facture() const;

  /**
   * @brief Displays the facture on a specific stream
   * @param os The output stream to use
   */
  void afficher_facture(std::ostream &os) const;

  /**
   * @brief Calculate the balance due for the facture
   * @return The total balance due for the facture
   */
  double calculer_balance() const;

  /**
   * @brief Finalizes the facture
   */
  void finaliser_facture();

  /**
   * @brief Saves the facture to a file
   */
  void enregistrer_facture() const;

  /**
   * @brief Sets the client linked to the facture
   * @param client The new client linked to the facture
   * @see Client
   */
  void set_client(Client *client);

  /**
   * @brief Sets the vehicle linked to the facture
   * @param vehicle The new vehicle linked to the facture
   * @see Vehicle
   */
  void set_vehicle(Vehicle *vehicle);

 private:
  /// @brief The id of the facture
  int _id;

  /// @brief The next id of the facture
  static int _facture_id_suivant;

  /// @brief The date of the facture
  std::string _date_facture;

  /// @brief The status of the facture
  int _status;

  /// @brief The balance due for the facture
  double _balance;

  /// @brief The client linked to the facture
  Client *_client;

  /// @brief The vehicle linked to the facture
  Vehicle *_vehicle;

  /// @brief The products linked to the facture
  std::vector<ProduitFacture> _produits;
};

#endif