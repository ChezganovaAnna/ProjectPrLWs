cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(sfml-lab-4)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype REQUIRED)
find_package(JPEG REQUIRED)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)

add_subdirectory(workshop1_1)
add_subdirectory(workshop1_2)
add_subdirectory(workshop1_3)
add_subdirectory(workshop1_4)