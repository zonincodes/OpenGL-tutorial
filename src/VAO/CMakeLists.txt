add_library(VAO src/VAO.cpp)
# target_include_directories(VAO PUBLIC ${PROJECT_SOURCE_DIR}/libs/glad/include)

target_include_directories(VAO PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${CMAKE_CURRENT_SOURCE_DIR}/../VBO/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../libs/glad/include
)