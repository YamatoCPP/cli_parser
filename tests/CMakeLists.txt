add_executable(test_cli_parser test_cli_parser.cpp)
find_package(GTest REQUIRED)

target_link_libraries(test_cli_parser PUBLIC cli_parser GTest::gtest GTest::gtest_main)
target_compile_options(test_cli_parser PRIVATE -Wall -Werror -O3)

add_test(NAME test_cli_parser COMMAND test_cli_parser)
