#ifndef __SERVICE_HPP__
#define __SERVICE_HPP__

#include <iostream>
#include <string>

#include "Produit.hpp"

/**
 * @brief Class Service
 * @details This class is used to represent a service
 * @see Produit
 */
class Service : public Produit {
 public:
  /**
   * @brief Construct a new Service object
   * @param nom The name of the service
   * @param prix The price of the service
   * @param temps_execution The execution time of the service
   */
  Service(const std::string& nom, double prix, double temps_execution);

  /**
   * @brief Construct a new Service object
   * @param nom The name of the service
   * @param prix The price of the service
   * @param temps_execution The execution time of the service
   * @param description The description of the service
   */
  Service(const std::string& nom, double prix, double temps_execution,
          const std::string& description);

  /**
   * @brief Display the service
   */
  void afficher() const override;

  /**
   * @brief Calculate the price of the service (price * execution time)
   * @return The total price of the service
   */
  double calculer_prix() const override;

  /**
   * @brief Get the type of the product
   * @return The type of the product
   */
  char get_type_produit() const override;

  /**
   * @brief Get the description of the service
   * @return The description of the service
   */
  const std::string& get_description() const;

  /**
   * @brief Set the description of the service
   * @param description The description of the service
   */
  void set_description(const std::string& description);

 private:
  std::string _description;
  double _temps_execution;
};

#endif