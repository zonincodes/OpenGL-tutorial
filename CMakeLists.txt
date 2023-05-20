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




configure_file(shaders/default/default.frag ${CMAKE_CURRENT_BINARY_DIR}/default.frag COPYONLY)
configure_file(shaders/default/default.vert ${CMAKE_CURRENT_BINARY_DIR}/default.vert COPYONLY)

configure_file(shaders/light/light.frag ${CMAKE_CURRENT_BINARY_DIR}/light.frag)
configure_file(shaders/light/light.vert ${CMAKE_CURRENT_BINARY_DIR}/light.vert)
configure_file(assets/brick-texture.png ${CMAKE_CURRENT_BINARY_DIR}/brick-texture.png COPYONLY)




target_link_libraries(${PROJECT_NAME} glad VBO VAO EBO shader textures stb_image camera glm)
# link libraries ubuntu source
target_link_libraries(${PROJECT_NAME}  glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES})
