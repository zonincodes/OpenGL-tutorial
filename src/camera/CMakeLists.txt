add_library(camera src/camera.cpp)
# target_include_directories(camera PUBLIC ${PROJECT_SOURCE_DIR}/libs/glad/include)

target_include_directories(camera PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${CMAKE_CURRENT_SOURCE_DIR}/../shader/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../libs/glad/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../libs/glm/include
)