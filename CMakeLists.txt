# Replace 'ProjectName' and 'PROJECT_NAME_SOURCES' with your project's name.
# You may want to add additional OS settings if needed.

cmake_minimum_required(VERSION 3.10)
project(ProjectName)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CONFIGURE_DEPENDS ON)

# Add GLFW headers and include
add_subdirectory(external/glfw)
include_directories(external/glfw/include)

# Include GLAD manually
add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

# OpenGL
find_package(OpenGL REQUIRED)

# Your source files
file(GLOB_RECURSE SOURCES src/*.cpp)

file(GLOB PROJECT_NAME_SOURCES
    src/*.cpp
)

add_executable(ProjectName
    main.cpp
    ${PROJECT_NAME_SOURCES}
)

# Include paths
target_include_directories(ProjectName
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link libraries
target_link_libraries(ProjectName
  PRIVATE
    glad
    glfw
    OpenGL::GL
)

# Optional Windows extras
if (WIN32)
    target_link_libraries(Teste PRIVATE opengl32)
endif()