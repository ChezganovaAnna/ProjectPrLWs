add_executable(workshop1_3 workshop1_3.cpp)


target_include_directories(workshop1_3 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(workshop1_3 PUBLIC cxx_std_17)
target_compile_definitions(workshop1_3 PRIVATE SFML_STATIC)

target_link_libraries(workshop1_3 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
