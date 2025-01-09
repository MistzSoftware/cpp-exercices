# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.15)

# Set the project name and specify C++ as the language
project(cpp-exercices LANGUAGES CXX)

# Set the C++ standard (e.g., C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the compiler (Clang in this case)
set(CMAKE_CXX_COMPILER "clang++")

###################################################################
######################## Factorial ################################
###################################################################

# Add the executable target
add_executable(factorial src/factorial.cpp)
target_compile_options(factorial PRIVATE -Wall -Wextra -Wpedantic)

# Add a custom target to run
add_custom_target(run_factorial
    COMMAND factorial
    DEPENDS project1
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

###################################################################
######################## BubbleSort ###############################
###################################################################

# Add the executable target
add_executable(bubblesort src/bubblesort.cpp)
target_compile_options(bubblesort PRIVATE -Wall -Wextra -Wpedantic)

# Add a custom target to run
add_custom_target(run_bubblesort
    COMMAND bubblesort
    DEPENDS bubblesort
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

###################################################################
######################## InsertionSort ############################
###################################################################

# Add the executable target
add_executable(insertionsort src/insertionsort.cpp)
target_compile_options(insertionsort PRIVATE -Wall -Wextra -Wpedantic)

# Add a custom target to run
add_custom_target(run_insertionsort
    COMMAND insertionsort
    DEPENDS insertionsort
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# TO USE it
# Step 1: run mkdir build && cd build
# Step 2: run cmake .. -DCMAKE_CXX_COMPILER=clang++
# Step 3: run cmake --build . --target [runner-name]