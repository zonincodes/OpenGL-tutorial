cmake_minimum_required(VERSION 3.1...3.22 FATAL_ERROR)
# project name
project(glfw_tutorial VERSION 0.1.0)

# OpenGL packages
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# executable
add_executable(${PROJECT_NAME} main.cpp)

# add_packages
find_package(glfw3 3.3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})

# sub library
add_library(glad glad.h glad.c khrplatform.h)
target_link_libraries(${PROJECT_NAME} glad)

# shader library
add_library(shaders shaderClass.h shaderClass.cpp)
target_link_libraries(${PROJECT_NAME} shaders)

# VOA
add_library(VAO VAO.h VAO.cpp)
target_link_libraries(${PROJECT_NAME} VAO)

add_library(EBO EBO.h EBO.cpp)
target_link_libraries(${PROJECT_NAME} EBO)
configure_file(shaders/default.frag ${CMAKE_CURRENT_BINARY_DIR}default.frag COPYONLY)
configure_file(shaders/default.vert ${CMAKE_CURRENT_BINARY_DIR}default.frag COPYONLY)



# Vertex Object Library
add_library(VBO VBO.h VBO.cpp)
target_link_libraries(${PROJECT_NAME} VBO)


# link libraries ubuntu source
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES})
