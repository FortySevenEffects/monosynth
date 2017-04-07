cmake_minimum_required(VERSION 3.0)

project(monosynth CXX)

# --

add_subdirectory(builder)
setup_avr_builder(atmega32u4 16) # Arduino Leonardo

# --

add_subdirectory(libraries)
add_subdirectory(sources)
