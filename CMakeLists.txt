project(zengine)

cmake_minimum_required(VERSION 2.8)

# Find packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(PNG REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

# Project source code
set(SOURCES
    src/engine/core/pngimage.cpp
    
    src/engine/errors/zexception.cpp
    src/engine/errors/zoutofrangeexception.cpp
    src/engine/errors/debug.cpp
    
    src/engine/render/renderer.cpp
    src/engine/render/shader.cpp
    src/engine/render/vertexarray.cpp
    src/engine/render/texture.cpp
    src/engine/render/camera.cpp
    
    src/engine/zapplication.cpp
    src/engine/zwindow.cpp
)

# Inlucde directories for libraries
set(INCLUDE_DIRS
    ${OPENGL_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    ${PNG_INCLUDE_DIRS}
)

# Configuration
include_directories(${INCLUDE_DIRS})
include_directories(include/)
include_directories(3rdparty/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# Compiling
add_library(${PROJECT_NAME} SHARED ${SOURCES})
add_library(${PROJECT_NAME}_static STATIC ${SOURCES})

# Linking
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

# Install
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY include/engine/ DESTINATION include/zengine)
install(DIRECTORY 3rdparty/GL/ DESTINATION include/GL)
