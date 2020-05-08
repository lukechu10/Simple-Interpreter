cmake_minimum_required(VERSION 3.10)

project(Interpreter VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src/include)

# add the executable
add_executable(Interpreter
  src/cpp/main.cpp
  src/cpp/Lexer.cpp
)

# include(CTest)
# enable_testing()

# # does the application run
# add_test(NAME Runs COMMAND Interpreter)
