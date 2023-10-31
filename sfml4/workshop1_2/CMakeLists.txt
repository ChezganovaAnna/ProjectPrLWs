add_executable(workshop1_2 workshop1_2.cpp)


target_include_directories(workshop1_2 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(workshop1_2 PUBLIC cxx_std_17)
target_compile_definitions(workshop1_2 PRIVATE SFML_STATIC)

target_link_libraries(workshop1_2 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
