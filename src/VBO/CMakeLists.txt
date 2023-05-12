add_library(VBO src/VBO.cpp)
target_include_directories(VBO PUBLIC ${PROJECT_SOURCE_DIR}/libs/glad/include)

target_include_directories(VBO PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)