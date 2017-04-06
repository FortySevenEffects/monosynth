cmake_minimum_required(VERSION 3.0)

project(monosynth CXX)

# --

add_subdirectory(builder)
setup_builder()

# --

add_subdirectory(libraries)
add_subdirectory(sources)
