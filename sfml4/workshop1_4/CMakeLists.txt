add_executable(workshop1_4 workshop1_4.cpp)


target_include_directories(workshop1_4 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(workshop1_4 PUBLIC cxx_std_17)
target_compile_definitions(workshop1_4 PRIVATE SFML_STATIC)

target_link_libraries(workshop1_4 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
