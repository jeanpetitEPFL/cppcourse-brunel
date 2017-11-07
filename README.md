CPPCOURSE-BRUNEL NETWORK
author : Jeanpetit Florent


the aim of this programm is to reproduce Mr Brunel's theory.

download this github
extract

## CMake

add an empty folder named "build"
in the terminal go to build

add command : cmake ..

add command : make

## Documentation

this sould compile the main programm ad update in the same time the documentation on Doxygen.
if you want separate compilation for documentation and program please go in CMakeLists.txt 
and remove "ALL" in the command "add_custom_target"

to compile documentation without the "ALL"

add command : make doc

## Run
add command : ./main to run the main program

## Plot 
to get a plot you can go to this adress https://cs116-plot.antoinealb.net/

or use the small python code "data.py"
after the running of the main program a document named spikes.gdf is created with every spikes (time and neuron's number)

add command : python data.py

this will open a window with the plot

## Run Tests

in termi,al go to build folder

add command : ./neuron_test to run google-tests

