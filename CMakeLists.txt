cmake_minimum_required(VERSION 3.28)
project(phi VERSION 0.1.0 LANGUAGES CXX)

# Print processor and compiler
message(STATUS "Processor: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ Compiler Version: ${CMAKE_CXX_COMPILER_VERSION}")

# Set standard version and requirements
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler specific options
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wall -Wextra -Wpedantic -Werror -Wextra -Wconversion -Wsign-conversion)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Werror -Wextra -Wconversion -Wsign-conversion)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4 /WX)
endif ()

# Fetch libraries
include(FetchContent)
FetchContent_Declare(GSL
        GIT_REPOSITORY "https://github.com/microsoft/GSL"
        GIT_TAG "v4.0.0"
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(GSL)

# OpenMP support
find_package(OpenMP)
if (OpenMP_CXX_FOUND)
    option(PHI_OPENMP_ENABLE "Enable OpenMP backend" ON)
    message(STATUS "OpenMP found: ${OpenMP_CXX_FOUND}")
else ()
    option(PHI_OPENMP_ENABLE "Enable OpenMP backend" OFF)
    message(PHI_OPENMP_ENABLE "OpenMP not found")
endif ()
message(STATUS "OpenMP enabled: ${PHI_OPENMP_ENABLE}")
if (PHI_OPENMP_ENABLE)
    link_libraries(OpenMP::OpenMP_CXX)
endif ()


# Set include directory
include_directories(include)

# Unit tests with google test
option(PHI_BUILD_TESTS "Build unit tests" ON)
message(STATUS "Build tests: ${PHI_BUILD_TESTS}")
if (PHI_BUILD_TESTS)
    #Fetch googletest
    FetchContent_Declare(googletest
            GIT_REPOSITORY "https://github.com/google/googletest"
            GIT_TAG "v1.15.2"
            GIT_SHALLOW TRUE)
    FetchContent_MakeAvailable(googletest)
endif ()

# Enable clang-tidy
option(PHI_ENABLE_CLANG_TIDY "Enable clang-tidy" ON)
message(STATUS "Enable clang-tidy: ${PHI_ENABLE_CLANG_TIDY}")
if (PHI_ENABLE_CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
endif ()

if (PHI_BUILD_TESTS)
    enable_testing()
    add_subdirectory(utest)
endif ()


# Example applications
option(PHI_BUILD_EXAMPLES "Build example applications" OFF)
message(STATUS "Build examples: ${PHI_BUILD_EXAMPLES}")
if (PHI_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif ()

