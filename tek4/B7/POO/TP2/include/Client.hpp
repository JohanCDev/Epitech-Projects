#ifndef __CLIENT_HPP__
#define __CLIENT_HPP__

#include <string>

/**
 * @brief Classe Client
 * @details This class is used to represent a client
 */
class Client {
 public:
  /**
   * @brief Construct a new Client object
   * @param nom The name of the client
   * @param adresse The address of the client
   * @param phone The phone number of the client
   */
  Client(const std::string& nom, const std::string& adresse,
         const std::string& phone);

  /**
   * @brief Gets the id of the client
   * @return The id of the client
   */
  int get_id() const;

  /**
   * @brief Gets the id of the next client
   * @return The id of the next client
   */
  int get_id_suivant() const;

  /**
   * @brief Gets the name of the client
   * @return The name of the client
   */
  const std::string& get_nom() const;

  /**
   * @brief Gets the address of the client
   * @return The address of the client
   */
  const std::string& get_adresse() const;

  /**
   * @brief Gets the phone number of the client
   * @return The phone number of the client
   */
  const std::string& get_phone() const;

 private:
  /// @brief The id of the client
  int _id;

  /// @brief The id of the next client
  static int _client_id_suivant;

  /// @brief The name of the client
  std::string _nom;

  /// @brief The address of the client
  std::string _adresse;

  /// @brief The phone number of the client
  std::string _phone;
};

#endif