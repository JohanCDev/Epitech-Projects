# TP 01

## Description

Ce projet est un projet de test pour le cours de programmation orientée objet donné par Eduardo Mendes Oliveira à l'UQAC lors du trimestre d'automne 2023.

## Build

Pour compiler le projet, vous avez 2 options:

1. Utiliser cmake, pour cela vous aurez besoin de cmake et d'un compilateur C++ (gcc, clang, etc.):

```bash
mkdir build
cd build
cmake ..
cd ..
cmake --build build
```

2. Utiliser g++ directement:

```bash
g++ -o TaskAdmin sources/main.cpp sources/Task.cpp sources/User.cpp sources/FileAdministrator.cpp -I include/
```

## Usage

Pour utiliser le programme, vous devez lancer le programme avec la commande suivante:

```bash
./TaskAdmin
```

## Test

Pour tester le projet, vous pouvez executer ce qui suit:

```bash
./TaskAdmin > test/result
diff test/result test/resultExpected
```

Si rien ne s'affiche, c'est que les tests sont passés avec succès.

Ils passent également automatiquement sur GitHub Actions lors d'un push sur la branche main.

## Auteurs

- Johan CHRILLESEN - [https://www.github.com/JohanCDev](https://www.github.com/JohanCDev)
