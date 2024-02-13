#include <iostream>

#include "Task.hpp"

Task::Task(unsigned int id, const std::string &title,
           const std::string &description, const std::string &creationDate,
           const std::string &deadline, const std::string &status)
    : _id(id),
      _title(title),
      _description(description),
      _creationDate(creationDate),
      _deadline(deadline),
      _status(status) {}

unsigned int Task::getId() const { return _id; }

const std::string &Task::getTitle() const { return _title; }

const std::string &Task::getDescription() const { return _description; }

const std::string &Task::getCreationDate() const { return _creationDate; }

const std::string &Task::getDeadline() const { return _deadline; }

const std::string &Task::getStatus() const { return _status; }

void Task::displayTask() const {
  std::cout << "--- Affichage de la tâche ---" << std::endl;
  std::cout << "ID : " << _id << std::endl;
  std::cout << "Titre : " << _title << std::endl;
  std::cout << "Description : " << _description << std::endl;
  std::cout << "Date de début : " << _creationDate << std::endl;
  std::cout << "Date de fin : " << _deadline << std::endl;
  std::cout << "Statut : " << _status << std::endl;
}