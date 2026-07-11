cmake_minimum_required(VERSION 3.10)
project(ChessBoard C)

# This generates compile_commands.json so clangd gives you perfect IntelliSense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Tell CMake which files to compile. 
# Replace these with the actual names of your C files containing your game loop, structs, and enums.
add_executable(chess main.c)
# Link the Raylib library and the standard math library (-lm)
target_link_libraries(chess raylib m)
