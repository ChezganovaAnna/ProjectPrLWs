
add_executable(09 main.cpp)


target_include_directories(09 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(09 PUBLIC cxx_std_17)
target_compile_definitions(09 PRIVATE SFML_STATIC)

target_link_libraries(09 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
