# Replace 'ProjectName' with your project's name.
# You may want to add additional OS settings if needed.

cmake_minimum_required(VERSION 3.10)
project(ProjectName)

set(CMAKE_CXX_STANDARD 17)

# Add GLFW headers and include
add_subdirectory(external/glfw)
include_directories(external/glfw/include)

# Your source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Create executable
add_executable(ProjectName ${SOURCES})

# Link GLFW
target_link_libraries(ProjectName PRIVATE glfw)

# Optional: Link with OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(ProjectName PRIVATE OpenGL::GL)

# Optional: On Windows, add extra dependencies
if (WIN32)
    target_link_libraries(ProjectName PRIVATE opengl32)
endif()