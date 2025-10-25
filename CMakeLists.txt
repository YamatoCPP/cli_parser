cmake_minimum_required(VERSION 4.1)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)
set(CXX_MODULE_STD ON)

project(cli_parser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(cli_parser src/cli_parser.cpp)

target_sources(cli_parser PUBLIC 
    FILE_SET cli_parser_modules TYPE CXX_MODULES
    FILES modules/cli_parser.cppm modules/cli_parser_types.cppm)

target_compile_options(cli_parser PRIVATE -Wall -Werror -O3)

install(TARGETS cli_parser 
    LIBRARY
    FILE_SET cli_parser_modules
        COMPONENT Development
        DESTINATION .
    CXX_MODULES_BMI
        COMPONENT Development
        DESTINATION modules/bmi
)

