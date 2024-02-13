#ifndef __FILEADMINISTRATOR_HPP__
#define __FILEADMINISTRATOR_HPP__

#include "User.hpp"

/**
 * @brief Class that manages the file system.
 */
class FileAdministrator {
 public:
  /**
   * @brief Saves the user's tasks in a file.
   * @param user User tasks to save.
   */
  static void saveTasks(const User &user);

  /**
   * @brief Loads the user's tasks from a file.
   * @param user User to load tasks.
   */
  static void loadTasks(User &user);
};

#endif  // __FILEADMINISTRATOR_HPP__
