# Replace 'ProjectName' with your project's name.
# You may want to add additional OS settings if needed.

cmake_minimum_required(VERSION 3.10)
project(ProjectName)

set(CMAKE_CXX_STANDARD 17)

# Add GLFW headers and include
add_subdirectory(external/glfw)
include_directories(external/glfw/include)

# Include GLAD manually
add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

# Your source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Create executable
add_executable(ProjectName ${SOURCES})

# Include directories
target_include_directories(ProjectName
  PUBLIC
    external/glad/include
    external/glfw/include
)

# Link libraries
target_link_libraries(ProjectName
  PRIVATE
    glad
    glfw
)

# Optional: Link with OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(ProjectName PRIVATE OpenGL::GL)

# Optional: On Windows, add extra dependencies
if (WIN32)
    target_link_libraries(ProjectName PRIVATE opengl32)
endif()