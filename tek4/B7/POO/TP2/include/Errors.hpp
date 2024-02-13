#ifndef __ERRORS_HPP__
#define __ERRORS_HPP__

#include <string>

/**
 * @brief Classe FactureFinaliseeException
 * @details This class is used to throw an exception when you try to modify a
 * finalized facture
 */
class FactureFinaliseeException : public std::exception {
 public:
  /**
   * @brief Construct a new FactureFinaliseeException object
   * @param message The message of the exception
   */
  FactureFinaliseeException(const std::string &message);

  /**
   * @brief Destroy the FactureFinaliseeException object
   */
  virtual ~FactureFinaliseeException() throw() = default;

  /**
   * @brief Gets the message of the exception
   * @return The message of the exception
   */
  const char *what() const throw();

 private:
  /// @brief The message of the exception
  std::string _message;
};

/**
 * @brief Classe FacturePasFinaliseeException
 * @details This class is used to throw an exception when you try to save a
 * facture without finalizing it
 */
class FacturePasFinaliseeException : public std::exception {
 public:
  /**
   * @brief Construct a new FacturePasFinaliseeException object
   * @param message The message of the exception
   */
  FacturePasFinaliseeException(const std::string &message);

  /**
   * @brief Destroy the FacturePasFinaliseeException object
   */
  virtual ~FacturePasFinaliseeException() throw() = default;

  /**
   * @brief Gets the message of the exception
   * @return The message of the exception
   */
  const char *what() const throw();

 private:
  /// @brief The message of the exception
  std::string _message;
};

#endif