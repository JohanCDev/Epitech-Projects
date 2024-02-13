#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include <string>

#include "Produit.hpp"

/**
 * @brief Class Piece
 * @details This class is used to represent a piece
 * @see Produit
 */
class Piece : public Produit {
 public:
  /**
   * @brief Construct a new Piece object
   * @param nom The name of the piece
   * @param prix The price of the piece
   * @param quantite_depot The quantity of the piece in the depot
   */
  Piece(const std::string& nom, double prix, int quantite_depot);

  /**
   * @brief Add a quantity of piece to the depot
   * @param quantite The quantity of piece to add
   */
  void ajouter_piece_depot(int quantite);

  /**
   * @brief Remove a quantity of piece from the depot
   * @param quantite The quantity of piece to remove
   */
  void soustraire_piece_depot(int quantite);

  /**
   * @brief Display the piece
   */
  void afficher() const override;

  /**
   * @brief Get the price of the piece
   * @return The price of the piece
   */
  double calculer_prix() const override;

  /**
   * @brief Get the type of the product
   * @return The type of the product
   */
  char get_type_produit() const override;

  /**
   * @brief Get the quantity of the piece in the depot
   * @return The quantity of the piece in the depot
   */
  int get_quantite_depot() const;

 private:
  /// @brief The quantity of the piece in the depot
  int _quantite_depot;
};

#endif