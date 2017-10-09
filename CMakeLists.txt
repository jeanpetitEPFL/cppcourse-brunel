# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 2.6)

#flag
set(CMAKE_CXX_FLAGS"-W -Wall -pedantic -std=c++11")

# Notre projet est étiqueté neuron
project(neuron)

# On indique que l'on veut un exécutable "main" 
add_executable(main main.cpp)


