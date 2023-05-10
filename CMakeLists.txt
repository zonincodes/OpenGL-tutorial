cmake_minimum_required(VERSION 3.1...3.22 FATAL_ERROR)

project(glfw_setup VERSION 0.1.0)
find_package(OpenGL REQUIRED)
add_executable(${PROJECT_NAME} main.cpp)


add_subdirectory(external/glfw)
add_subdirectory(external/linmath)
add_subdirectory(external/glad)

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/include
    PUBLIC external/linmath
    PUBLIC external/glad
    )
link_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/src
    PUBLIC external/linmath
    PUBLIC external/glad
    )
target_link_libraries(${PROJECT_NAME} glfw linmath glad)