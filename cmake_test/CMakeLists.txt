cmake_minimum_required(VERSION 2.8)

project(app_project)

add_subdirectory(tzf)

add_executable(myapp main.cpp)
target_link_libraries(myapp test)

install(TARGETS myapp DESTINATION bin)