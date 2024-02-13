#include <iostream>

#include "FileAdministrator.hpp"
#include "Task.hpp"
#include "User.hpp"

class Test {
 public:
  static void lancerTests() {
    // Test 1: Création et affichage d'une tâche
    Task tache1(1, "Acheter du pain", "Aller à la boulangerie", "01/10/2023",
                "01/10/2023", "En cours");
    tache1.displayTask();
    // Test 2: Création d'un utilisateur et ajout d'une tâche
    User utilisateur("John Doe", "john.doe@example.com");
    utilisateur.addTask(tache1);
    utilisateur.displayAllTasks();
    // Test 3: Sauvegarde des tâches dans un fichier

    FileAdministrator::saveTasks(utilisateur);
    // Test 4: Chargement des tâches depuis un fichier
    User utilisateur2("John Doe", "john.doe@example.com");
    FileAdministrator::loadTasks(utilisateur2);
    utilisateur2.displayAllTasks();
  }
};

int main() {
  Test::lancerTests();
  return 0;
}