add_library(EBO src/EBO.cpp)
target_include_directories(EBO PUBLIC ${PROJECT_SOURCE_DIR}/libs/glad/include)

target_include_directories(EBO PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${CMAKE_CURRENT_SOURCE_DIR}/../../libs/glad/include
)