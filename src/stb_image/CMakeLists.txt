add_library(stb_image src/stb_image.cpp)
target_include_directories(stb_image PUBLIC ${PROJECT_SOURCE_DIR}/libs/glad/include)

target_include_directories(stb_image PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${CMAKE_CURRENT_SOURCE_DIR}/../../libs/glad/include
)