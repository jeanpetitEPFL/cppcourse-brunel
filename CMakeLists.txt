# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 2.6)

#flag
set(CMAKE_CXX_FLAGS"-W -Wall -pedantic -std=c++11")

# Notre projet est étiqueté neuron
project(neuron)


#google-test
enable_testing()
add_subdirectory(GTEST_DIR)
include_directories(${GTEST_DIR/googletest}/include ${GTEST_DIR/googletest})

# On indique que l'on veut un exécutable "main" 
add_executable(main main_2.cpp neuron_2.cpp network_2.cpp)

#executables pour google-test
add_executable(neuron_test neuron_2.cpp neuron_test.cpp)
target_link_libraries(neuron_test gtest gtest_main)
add_test(neuron_test neuron_test)

