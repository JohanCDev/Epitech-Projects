#include <iostream>

#include "User.hpp"

User::User(const std::string &name, const std::string &email)
    : _name(name), _email(email), _tasksListCharged(false) {}

void User::addTask(const Task &task) { _tasksList.push_back(task); }

void User::removeTask(unsigned int id) {
  bool found = false;
  for (auto it = _tasksList.begin(); it != _tasksList.end(); ++it) {
    if (it->getId() == id) {
      found = true;
      _tasksList.erase(it);
      break;
    }
  }
  if (!found) {
    std::cerr << "La tâche " << id << " n'existe pas." << std::endl;
  }
}

static void displayTaskForList(const Task &task) {
  std::cout << task.getId() << ") "
            << "[" << task.getStatus() << "] " << task.getTitle() << " - "
            << task.getDescription() << " (" << task.getCreationDate() << " - "
            << task.getDeadline() << ")" << std::endl;
}

void User::displayAllTasks() const {
  if (_tasksListCharged) {
    std::cout << "--- Affichage des tâches de l'utilisateur " << _name
              << " après chargement ---" << std::endl;
  } else {
    std::cout << "--- Affichage des tâches de l'utilisateur " << _name << " ---"
              << std::endl;
  }

  if (_tasksList.empty()) {
    std::cerr << "Aucune tâche à afficher." << std::endl;
    return;
  }

  for (const auto &task : _tasksList) {
    displayTaskForList(task);
  }
}

void User::setTasksListCharged(bool tasksListCharged) {
  _tasksListCharged = tasksListCharged;
}

const std::string &User::getName() const { return _name; }

const std::vector<Task> &User::getTasksList() const { return _tasksList; }
