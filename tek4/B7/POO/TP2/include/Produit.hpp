#ifndef __PRODUIT_HPP__
#define __PRODUIT_HPP__

#include <string>

/**
 * @brief Class Produit
 * @details This class is used to represent a product
 */
class Produit {
 public:
  /**
   * @brief Construct a new Produit object
   * @param nom The name of the product
   * @param prix The price of the product
   */
  Produit(const std::string& nom, double prix);

  /**
   * @brief Destroy the Produit object
   */
  virtual ~Produit() = default;

  /**
   * @brief Display the product
   */
  virtual void afficher() const = 0;

  /**
   * @brief Get the name of the product
   * @return The name of the product
   */
  const std::string& get_nom() const;

  /**
   * @brief Get the price of the product
   * @return The price of the product
   */
  virtual double calculer_prix() const = 0;

  /**
   * @brief Get the type of the product
   * @return The type of the product (P for Piece, S for Service)
   */
  virtual char get_type_produit() const = 0;

  /**
   * @brief Get the price of the product
   * @return The price of the product
   */
  double get_prix() const;

 protected:
  /// @brief The next id of the product
  static int _produit_id_suivant;

 private:
  /// @brief The id of the product
  int _id;

  /// @brief The name of the product
  std::string _nom;

  /// @brief The price of the product
  double _prix;
};

#endif