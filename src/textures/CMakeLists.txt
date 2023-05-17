add_library(textures src/shaderClass.cpp)
target_include_directories(textures PUBLIC ${PROJECT_SOURCE_DIR}/libs/glad/include)

target_include_directories(textures PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)