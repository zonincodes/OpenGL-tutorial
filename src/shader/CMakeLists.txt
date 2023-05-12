add_library(shader src/shaderClass.cpp)
target_include_directories(shader PUBLIC ${PROJECT_SOURCE_DIR}/libs/glad/include)

target_include_directories(shader PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)