#include <fstream>
#include <iostream>

#include "FileAdministrator.hpp"

void FileAdministrator::saveTasks(const User &user) {
  std::cout << "--- Sauvegarde des tâches dans le fichier ---" << std::endl;
  const std::string &filename = user.getName() + "Tasks.txt";
  std::ofstream file(filename, std::ios::out | std::ios::trunc);
  if (file) {
    for (const auto &task : user.getTasksList()) {
      file << task.getId() << std::endl;
      file << task.getTitle() << std::endl;
      file << task.getDescription() << std::endl;
      file << task.getCreationDate() << std::endl;
      file << task.getDeadline() << std::endl;
      file << task.getStatus() << std::endl;
    }
    file.close();
  } else {
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
  }
  std::cout << "Les tâches de l'utilisateur " << user.getName()
            << " ont été sauvegardées avec succès." << std::endl;
}

void FileAdministrator::loadTasks(User &user) {
  std::cout << "--- Chargement des tâches depuis le fichier ---" << std::endl;
  const std::string &filename = user.getName() + "Tasks.txt";
  std::ifstream file(filename, std::ios::in);
  if (file) {
    std::string line;
    while (std::getline(file, line)) {
      unsigned int id = std::stoi(line);
      std::getline(file, line);
      std::string title = line;
      std::getline(file, line);
      std::string description = line;
      std::getline(file, line);
      std::string creationDate = line;
      std::getline(file, line);
      std::string deadline = line;
      std::getline(file, line);
      std::string status = line;
      Task task(id, title, description, creationDate, deadline, status);
      user.addTask(task);
    }
    file.close();
  } else {
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
  }
  user.setTasksListCharged(true);
  std::cout << "Les tâches de l'utilisateur " << user.getName()
            << " ont été chargées avec succès." << std::endl;
}