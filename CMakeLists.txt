cmake_minimum_required(VERSION 3.16)
project(kiraged2dengine)

set(CMAKE_CXX_STANDARD 14)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libraries/glfw-3.3.2)
add_subdirectory(libraries/glad)

find_package(OpenGL REQUIRED)

add_executable(kiraged2dengine main.cpp engine/GameWindow.cpp engine/GameWindow.h example/ExampleGame.cpp example/ExampleGame.h engine/shape/Shape.h engine/shape/Triangle.cpp engine/shape/Triangle.h engine/position/Point.cpp engine/position/Point.h engine/shape/Rectangle.cpp engine/shape/Rectangle.h engine/position/Dimension.cpp engine/position/Dimension.h engine/event/MouseEvents.h)
target_link_libraries(kiraged2dengine glfw)
target_link_libraries(kiraged2dengine OpenGL::GL)
target_link_libraries(kiraged2dengine glad)

