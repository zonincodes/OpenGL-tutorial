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

# sub directories glad
# add_subdirectory(external/glad)
# target_include_directories(${PROJECT_NAME} PUBLIC external/glad)
# target_link_directories(${PROJECT_NAME} PUBLIC external/glad)
add_library(glad glad.h glad.c khrplatform.h)
target_link_libraries(${PROJECT_NAME} glad)

# headers
add_library(shaders shaderClass.h shaderClass.cpp)
target_link_libraries(${PROJECT_NAME} shaders)
# link headers


# link libraries ubuntu source
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES})
