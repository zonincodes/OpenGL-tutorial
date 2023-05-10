cmake_minimum_required(VERSION 3.1...3.22 FATAL_ERROR)

project(glfw_tutorial VERSION 0.1.0)
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp)

find_package(glfw3 3.3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})

add_subdirectory(external/glad)

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/glad
    )
link_directories(${PROJECT_NAME} 
    PUBLIC external/glad
    )
target_link_libraries(${PROJECT_NAME}  glad)
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES})
