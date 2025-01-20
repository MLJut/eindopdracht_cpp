# Set the minimum verison
cmake_minimum_required(VERSION 3.27)

# Set CMAKE_TOOLCHAIN_FILE to make CMake recognize the vcpkg environment
# vcpkg allows for installing libraries like libcurl and curlpp
set(X_VCPKG_APPLOCAL_DEPS_INSTALL ON)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/tools/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

# Define the project
project(CPLUS VERSION 0.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

# Set build output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/output")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/output")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/output")

# Find required libs
find_package(GTest CONFIG REQUIRED)
# find_package(boost CONFIG REQUIRED)  # check if specific boost libs are possible rather than all of them
# find_package(CURL CONFIG REQUIRED)
find_package(cpr CONFIG REQUIRED)

# Add lib
add_subdirectory(${CMAKE_SOURCE_DIR}/lib)

# Add src
add_subdirectory(${CMAKE_SOURCE_DIR}/src)

# Add tests
# add_subdirectory(${CMAKE_SOURCE_DIR}/tests)

# Copy resources to exe directory
file(COPY "${CMAKE_SOURCE_DIR}/resources" DESTINATION "${PROJECT_BINARY_DIR}/output")

# -- [ Install ] --

# Install executable
install(TARGETS CPLUS DESTINATION bin)