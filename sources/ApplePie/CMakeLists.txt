file (GLOB_RECURSE Headers *.hpp)
file (GLOB_RECURSE Implementations *.cpp)
add_library (ApplePie STATIC ${Headers} ${Implementations})
set_target_properties (ApplePie PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib" LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib" RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
