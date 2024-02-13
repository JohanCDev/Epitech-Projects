#ifndef __PRODUITFACTURE_HPP__
#define __PRODUITFACTURE_HPP__

#include <iostream>

#include "Produit.hpp"

/**
 * @brief Class ProduitFacture
 * @details This class is used to represent a product in a facture
 */
class ProduitFacture {
 public:
  /**
   * @brief Construct a new ProduitFacture object
   * @param produit The product
   * @param quantite The quantity of the product
   */
  ProduitFacture(Produit* produit, int quantite);

  /**
   * @brief Displays the product
   */
  void afficher_produit() const;

  /**
   * @brief Displays the product using the << operator
   * @param os The output stream
   * @param pfacture The product
   */
  friend std::ostream& operator<<(std::ostream& os,
                                  const ProduitFacture& pfacture);

  /**
   * @brief Sets the quantity of the product
   * @param quantite The quantity of the product
   */
  void set_quantite(int quantite);

  /**
   * @brief Gets the product
   * @return The product
   */
  Produit* get_produit() const;

  /**
   * @brief Gets the quantity of the product
   * @return The quantity of the product
   */
  int get_quantite() const;

  /**
   * @brief Gets the total price of the product
   * @return The total price of the product
   */
  double get_prix_total() const;

 private:
  /// @brief The id of the product
  int _id;

  /// @brief The next id of the product
  static int _id_suivant;

  /// @brief The quantity of the product
  int _quantite;

  /// @brief The total price of the product
  double _prix_total;

  /// @brief The product
  Produit* _produit;
};

#endif