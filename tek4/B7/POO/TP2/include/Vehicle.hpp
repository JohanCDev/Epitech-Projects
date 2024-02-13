#ifndef __VEHICLE_HPP__
#define __VEHICLE_HPP__

#include <string>

/**
 * @brief Class Vehicle
 * @details This class is used to represent a vehicle
 * @see Client
 */
class Vehicle {
 public:
  /**
   * @brief Construct a new Vehicle object
   * @param plaque The plaque of the vehicle
   * @param modele The model of the vehicle
   * @param annee The year of the vehicle
   * @param type The type of the vehicle
   */
  Vehicle(const std::string& plaque, const std::string& modele,
          const std::string& annee, const std::string& type);

  /**
   * @brief Gets the id of the vehicle object
   * @return The id of the vehicle object
   */
  int get_id() const;

  /**
   * @brief Gets the next id of the vehicle object
   * @return The next id of the vehicle object
   */
  int get_id_suivant() const;

  /**
   * @brief Gets the plaque of the vehicle object
   * @return The plaque of the vehicle object
   */
  const std::string& get_plaque() const;

  /**
   * @brief Gets the model of the vehicle object
   * @return The model of the vehicle object
   */
  const std::string& get_modele() const;

  /**
   * @brief Gets the year of the vehicle object
   * @return The year of the vehicle object
   */
  const std::string& get_annee() const;

  /**
   * @brief Gets the type of the vehicle object
   * @return The type of the vehicle object
   */
  const std::string& get_type() const;

  /**
   * @brief Sets the next id of the vehicle object
   * @param id_suivant The next id of the vehicle object
   */
  void set_id_suivant(int id_suivant);

 private:
  /// @brief The id of the vehicle object
  int _id;
  /// @brief The next id of the vehicle object
  static int _id_suivant;

  /// @brief The plaque of the vehicle object
  std::string _plaque;

  /// @brief The model of the vehicle object
  std::string _modele;

  /// @brief The year of the vehicle object
  std::string _annee;

  /// @brief The type of the vehicle object
  std::string _type;
};

#endif