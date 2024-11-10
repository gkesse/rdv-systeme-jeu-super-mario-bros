# Introduction

Bienvenue dans ce tutoriel consacré à la présentation du processus de conception d’un système de jeu de Super Mario Bros en C++ avec Qt.

# Construction d’un projet C++ avec CMake sous VSCode

* Nous installons l’extension (WSL) dans l’éditeur (VSCode) pour développer des programme C/C++ à partir de l’éditeur (VSCode) sous l’environnement (WSL).

// VSCode (Extensions)
```
VSCode > Extensions > WSL > Install
```

* Nous ouvrons le dossier de projet dans l’environnement (WSL) sous Windows avec l’éditeur (VSCode).

// VSCode
```
Barre de recherche > Show and Run Commands
> WSL: Open Folder in WSL
Dossier > v01 > Sélectionner un dossier
```

* Nous installons l’extension (C/C++ IntelliSense Microsoft) dans l’éditeur (VSCode) pour utiliser l’auto-complétions lors du développement des programmes C/C++.

// VSCode (Extensions)
```
VSCode > Extensions > C/C++ > Install
```

* Nous installons l’extension (CMake) dans l’éditeur (VSCode) pour utiliser l’auto-complétions lors du développement des règles CMake.

// VSCode (Extensions)
```
VSCode > Extensions > CMake > Install
```

* Nous installons l’extension (CMake Tools) dans l’éditeur (VSCode) pour exécuter des commandes CMake.

// VSCode (Extensions)
```
VSCode > Extensions > CMake Tools > Install
```

* Nous installons l’extension (CMake Tools) dans l’éditeur (VSCode) pour exécuter des commandes CMake.

// VSCode (CMakeLists.txt)
```
Barre de recherche > Show and Run Commands 
> CMake: Quick Start
Name : ReadyMario
C++ : Create a C++ project
Executable : Create an executable
OK > OK
```

* Nous éditons le fichier (CMakeLists.txt) pour compiler le fichier (main.cpp).

// CMakeLists.txt
```
cmake_minimum_required(VERSION 3.5.0)
project(ReadyMario VERSION 0.1.0 LANGUAGES C CXX)
...
add_executable(ReadyMario main.cpp) 
```

* Nous éditons le fichier (main.cpp) pour afficher un message à l’écran.

// main.cpp
```
#include <iostream>
...
int main(int argc, char *argv[])
{
    std::cout << "Démarrage de l'application..." << std::endl;
    return 0;
}
```

* Nous sélectionnons le Kit de développement (GCC) pour compiler le projet avec le compilateur GCC dans l’éditeur (VSCode).

// VSCode (GCC)
```
CMake Tools > Configure > Select a Kit > GCC 11.4.0 x86_64-linux-gnu
```

* Nous sélectionnons la variante (Debug) pour compiler le projet en mode débogage dans l’éditeur (VSCode).

// VSCode (Debug)
```
CMake Tools > Configure > Set Variant > Debug
```

* Nous sélectionnons la règle (all) pour construire tout le projet dans l’éditeur (VSCode).

// VSCode (Build)
```
CMake Tools > Build > Set Build Target > all
```

* Nous démarrons la construction du projet dans l’éditeur (VSCode).

// VSCode (Build)
```
CMake Tools > Build > Run
```

* Nous démarrons l’exécution du projet dans l’éditeur (VSCode).

// VSCode (Launch)
```
CMake Tools > Launch > Run
```

[image_01.png](./img/image_01.png "image_01.png")

# Débogage d’un projet C++ avec CMake sous VSCode

* Nous cliquons sur la ligne (5) dans le fichier (main.cpp) pour placer un point d’arrêt dans l’éditeur (VSCode).

// main.cpp
```
Cliquer sur la ligne (5) pour placer un point d’arrêt (Breakpoint)
``` 

* Nous démarrons le débogage du projet dans l’éditeur (VSCode).

// VSCode (Debug)
```
CMake Tools > Debug > Run
```

* Nous affichons les variables de débogage dans l’éditeur (VSCode).

// VSCode (Debug)
```
Débogueur > Variables > Locals
```

* Nous affichons la pile des appels dans l’éditeur (VSCode).

// VSCode (Debug)
```
Débogueur > Call Stacks
```

# Construction d’un projet C++ en ligne de commande avec CMake

* Nous éditons le script (makes.sh) pour construire le projet en ligne de commande à partir de la commande (make).

// build-cmd/make.sh
```
MAKE_CMD="$1"
MAKE_ARGS=""
shift
...
while test $# -gt 0
do
    MAKE_ARGS="$MAKE_ARGS $1"
    shift
done
...
make -f commands.mak $MAKE_CMD ARGS="$MAKE_ARGS"
```

* Nous éditons le fichier (commands.mak) pour définir les règles de construction du projet en ligne de commande à partir de la commande (make).

// build-cmd/commands.mak
```
SRC_DIR = ..
BUILD_DIR = ../build
TARGET_NAME = ReadyMario
SETUP_NAME = $(BUILD_DIR)/$(TARGET_NAME)
...
all: clean_exe cmake compile run
...
cmake:
	@echo
	@cmake -B $(BUILD_DIR) -S $(SRC_DIR)
compile:
	@echo
	@make -C $(BUILD_DIR)
clean_exe:
	@echo
	@rm -f $(SETUP_NAME)
clean: clean_exe
	@echo
	@make -C $(BUILD_DIR) clean
clean_all:
	@echo
	@rm -rf $(BUILD_DIR)/*
run:
	@echo
	@./envs.sh && $(SETUP_NAME) $(ARGS)
```

* Nous créons le fichier (envs.sh) qui stockera les variables d’environnement du projet.

// Fichier
```
build-cmd/envs.sh
```

* Nous modifions les permissions du fichier (makes.sh) pour le rendre exécutable.

// Terminal
```
chmod a+x makes.sh
```

* Nous modifions les permissions du fichier (envs.sh) pour le rendre exécutable.

// Terminal
```
chmod a+x envs.sh
```

* Nous ouvrons un terminal dans l’éditeur (VSCode) pour la construction du projet.

// VSCode (Terminal)
```
View > Terminal
```

* Nous démarrons la construction du projet avec le script (makes.sh).

// Terminal
```
./makes.sh all
```

# Construction d’un projet C++ Qt avec CMake

* Nous récupérons le chemin du répertoire des fichiers d’en-tête C++ de Qt dans l’environnement (WSL).

// Windows
```
Explorer > Linux > Ubuntu
\\wsl.localhost\Ubuntu\home\admins\Qt5.14.2\5.14.2\gcc_64\include
/home/admins/Qt5.14.2/5.14.2/gcc_64/include 
```

* Nous ouvrons le fichier de configurations C/C++ (c_cpp_properties.json) dans l’éditeur (VSCode).

// VSCode
```
Barre de recherche > Show and Run Commands 
> C/C++: Edit Configurations (JSON) 
```

* Nous éditons le fichier de configurations C/C++ (c_cpp_properties.json) pour configurer les chemins des répertoires des fichiers d’en-tête C++ de Qt et le chemin du compilateur C++ (g++).

// .vscode/c_cpp_properties.json
```
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/home/admins/Qt5.14.2/5.14.2/gcc_64/include",
                "/home/admins/Qt5.14.2/5.14.2/gcc_64/include/QtCore",
                "/home/admins/Qt5.14.2/5.14.2/gcc_64/include/QtWidgets"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/g++",
            "cStandard": "gnu17",
            "cppStandard": "gnu++17",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
} 
```

* Nous modifions le fichier (CMakeLists.txt) pour charger les fichiers d’en-tête et les librairies associés à la classe (QMainWindow).

// CMakeLists.txt
```
cmake_minimum_required(VERSION 3.5.0)
project(ReadyMario VERSION 0.1.0 LANGUAGES C CXX)
...
find_package(Qt5 REQUIRED COMPONENTS
Widgets
)
...
add_executable(ReadyMario main.cpp)
...
target_link_libraries (ReadyMario
Qt5::Widgets
)
```

* Nous modifions le fichier (main.cpp) pour afficher la fenêtre principale avec la classe (QMainWindow).

// main.cpp
```
#include <QApplication>
#include <QMainWindow>
...
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow mainWin;
    mainWin.show();
    return a.exec();
}
```

* Nous démarrons la construction du projet avec le script (makes.sh).

// Terminal
```
./makes.sh all
```

# Contacts

