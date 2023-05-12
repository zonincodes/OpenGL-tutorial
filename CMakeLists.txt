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
# add_library(glad glad.h glad.c khrplatform.h)
# target_link_libraries(${PROJECT_NAME} glad)

#glad
add_subdirectory(libs)

# shader library
add_library(shaders shaderClass.h shaderClass.cpp)
target_include_directories(shaders PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/include)

# VOA
add_library(VAO VAO.h VAO.cpp)
target_include_directories(VAO PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/include)

# EBO
add_library(EBO EBO.h EBO.cpp)
target_include_directories(EBO PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/include)

configure_file(shaders/default.frag ${CMAKE_CURRENT_BINARY_DIR}/default.frag COPYONLY)
configure_file(shaders/default.vert ${CMAKE_CURRENT_BINARY_DIR}/default.vert COPYONLY)



# Vertex Object Library
add_library(VBO VBO.h VBO.cpp)
target_include_directories(VBO PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/include)


# link libraries ubuntu source
target_link_libraries(${PROJECT_NAME} PRIVATE glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} VBO VAO EBO glad shaders)
