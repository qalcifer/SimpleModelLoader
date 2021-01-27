cmake_minimum_required(VERSION 3.13)

set(SRC "src/main.cpp"
        "src/camera.hpp"
        "src/camera.cpp"
        "src/shader.hpp"
        "src/shader.cpp"
        "src/mesh.hpp"
        "src/mesh.cpp"
        "src/model.hpp"
        "src/model.cpp")

project(SimpleModelLoader LANGUAGES CXX)
add_executable(${PROJECT_NAME} ${SRC})

find_package(OpenGL REQUIRED)
add_dependencies(${PROJECT_NAME} OpenGL::OpenGL)
target_link_libraries(${PROJECT_NAME} OpenGL::OpenGL)

find_package(GLEW REQUIRED)
target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARIES})

find_package(glm REQUIRED)
link_directories(${GLM_LIBRARY_DIRS})

find_package(glfw3 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw)

find_package(ASSIMP REQUIRED)
target_link_libraries(${PROJECT_NAME} ${ASSIMP_LIBRARIES})
