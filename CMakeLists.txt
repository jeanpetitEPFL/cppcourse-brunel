# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 2.6)

#flag
set(CMAKE_CXX_FLAGS"-W -Wall -pedantic -std=c++11")

# Notre projet est étiqueté neuron
project(neuron)

# Créé des variables avec les fichiers à compiler
set(SRCS
	neuron.cpp
	main.cpp
	)
	
set(HEADERS
	neuron.hpp
	)

# On indique que l'on veut un exécutable "main" compilé à partir des fichiers décrit par les variables SRCS et HEADERS
add_executable(main main.cpp ${SRCS} ${HEADERS})

