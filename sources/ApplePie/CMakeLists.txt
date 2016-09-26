file (GLOB_RECURSE Headers *.hpp)
file (GLOB_RECURSE Implementations *.cpp)
add_library (ApplePie STATIC ${Headers} ${Implementations})
