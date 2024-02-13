#ifndef __TASK_HPP__
#define __TASK_HPP__

#include <string>

/// @brief Class that represents a task.
class Task {
 public:
  /**
   * @brief Construct a new Task object.
   * @param id Task id.
   * @param title Task title.
   * @param description Task description.
   * @param creationDate Task creation date.
   * @param deadline Task deadline.
   * @param status Task status.
   */
  Task(unsigned int id, const std::string &title,
       const std::string &description, const std::string &creationDate,
       const std::string &deadline, const std::string &status);

  /**
   * @brief Gets the task id.
   * @return Task id.
   */
  unsigned int getId() const;

  /**
   * @brief Gets the task title.
   * @return Task title.
   */
  const std::string &getTitle() const;

  /**
   * @brief Gets the task description.
   * @return Task description.
   */
  const std::string &getDescription() const;

  /**
   * @brief Gets the task creation date.
   * @return Task creation date.
   */
  const std::string &getCreationDate() const;

  /**
   * @brief Gets the task deadline.
   * @return Task deadline.
   */
  const std::string &getDeadline() const;

  /**
   * @brief Gets the task status.
   * @return Task status.
   */
  const std::string &getStatus() const;

  /// @brief Displays the task.
  void displayTask() const;

 private:
  /// @brief Task id.
  unsigned int _id;

  /// @brief Task title.
  std::string _title;

  /// @brief Task description.
  std::string _description;

  /// @brief Task creation date.
  std::string _creationDate;

  /// @brief Task deadline.
  std::string _deadline;

  /// @brief Task status.
  std::string _status;
};

#endif