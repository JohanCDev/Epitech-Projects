#ifndef __USER_HPP__
#define __USER_HPP__

#include <vector>

#include "Task.hpp"

/// @brief Class that represents a user.
class User {
 public:
  /**
   * @brief Construct a new User object.
   * @param name User name.
   * @param email User email.
   */
  User(const std::string &name, const std::string &email);

  /**
   * @brief Adds a task to the user's tasks list.
   * @param task Task to add.
   */
  void addTask(const Task &task);

  /**
   * @brief Removes a task from the user's tasks list.
   * @param id Task id to remove.
   */
  void removeTask(unsigned int id);

  /**
   * @brief Gets a task from the user's tasks list.
   * @param id Task id to get.
   * @return Task from the user's tasks list.
   */
  void displayAllTasks() const;

  /**
   * @brief Changed the tasksListCharged.
   * @param tasksListCharged tasksListCharged new value.
   */
  void setTasksListCharged(bool tasksListCharged);

  /**
   * @brief Gets the name of the user.
   * @return Name of the user.
   */
  const std::string &getName() const;

  /**
   * @brief Gets the email of the user.
   * @return Email of the user.
   */
  const std::vector<Task> &getTasksList() const;

 private:
  /// @brief User name.
  std::string _name;

  /// @brief User email.
  std::string _email;

  /// @brief User tasks list.
  std::vector<Task> _tasksList;

  /// @brief User tasks list charged.
  bool _tasksListCharged;
};

#endif  // __USER_HPP__