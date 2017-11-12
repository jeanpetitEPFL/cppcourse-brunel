#version
cmake_minimum_required(VERSION 2.6)

#flag
set(CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11")
#without this command, C++11 library not found in my VM
add_definitions("-std=c++11")
# project named neuron
project(neuron)


#google-test
enable_testing()

find_package(GTest)
include_directories(${GTEST_INCLUDE_DIRS}/include ${GTEST_INCLUDE_DIRS})

#add_subdirectory(googletest-master)
#include_directories(googletest-master/googletest/include gtest)


# executable "main" 
add_executable(main main_2.cpp neuron.cpp network.cpp)

#executables for google-test
add_executable(neuron_test neuron.cpp network.cpp neuron_test.cpp)
target_link_libraries(neuron_test gtest gtest_main ${GTEST_BOTH_LIBRARIES} pthread )
add_test(neuron_test neuron_test)



###### Doxygen generation ######

# We first check if Doxygen is present.
find_package(Doxygen)
if(DOXYGEN_FOUND)

    # We then check if the Doxygen.in configuration file exists
    IF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
        message(FATAL_ERROR "Doxygen configuration file is needed to build the documentation:
         - ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in not found.
         - Generate one in the project folder with doxygen -g Doxyfile.in")
    ENDIF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)

    # We configure the doxyfile for make.
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc # ALL
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
ELSE(DOXYGEN_FOUND)
    message(FATAL_ERROR "Doxygen is needed to build the documentation.")
ENDIF(DOXYGEN_FOUND)
