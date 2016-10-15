set (APPLE_PIE_TESTS_DATA_DIR "${CMAKE_BINARY_DIR}/bin/data")
configure_file ("${CMAKE_CURRENT_SOURCE_DIR}/Defines.hpp.cmake" "${CMAKE_CURRENT_SOURCE_DIR}/Defines.hpp")

add_executable (TestLexer TestLexer.cpp)
target_link_libraries (TestLexer Dwarf)
add_test (NAME test_lexer COMMAND TestLexer)

set_target_properties (TestLexer PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib" LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib" RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
