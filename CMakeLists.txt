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
add_subdirectory(src)




configure_file(shaders/default.frag ${CMAKE_CURRENT_BINARY_DIR}/default.frag COPYONLY)
configure_file(shaders/default.vert ${CMAKE_CURRENT_BINARY_DIR}/default.vert COPYONLY)




target_link_libraries(${PROJECT_NAME} glad VBO VAO EBO shader stb_image)
# link libraries ubuntu source
target_link_libraries(${PROJECT_NAME}  glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES})
