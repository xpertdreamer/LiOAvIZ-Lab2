cmake_minimum_required(VERSION 3.31)
project(LiOAvIZ-Lab2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_compile_options(
        "$<$<CONFIG:DEBUG>:-Wall>"
        "$<$<CONFIG:DEBUG>:-Wextra>"
        "$<$<CONFIG:DEBUG>:-pedantic>"
        "$<$<CONFIG:DEBUG>:-Werror>"
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -DNDEBUG -ffast-math -funroll-loops")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -pedantic -Werror")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g -march=native")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -march=native -DNDEBUG")
elseif(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "/O2 /fp:fast /DNDEBUG")
    set(CMAKE_CXX_FLAGS_DEBUG "/Zi /Od /W4")
endif()

add_executable(lab2
        src/main.cpp
        src/matrix.cpp
        src/matrix.h
        src/sorts.h
        src/sorts.cpp
)

target_include_directories(lab2 PRIVATE src)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(lab2 PRIVATE
            -fno-exceptions
            -fno-rtti
    )

    # Link Time Optimization
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        target_compile_options(lab2 PRIVATE -flto)
        target_link_options(lab2 PRIVATE -flto)
    endif()
endif()

target_precompile_headers(lab2 PRIVATE
        <vector>
        <iostream>
        <chrono>
        <algorithm>
)

option(ENABLE_PROFILING "Enable profiling support" OFF)
if(ENABLE_PROFILING)
    target_compile_options(lab2 PRIVATE -pg)
    target_link_options(lab2 PRIVATE -pg)
endif()

option(ENABLE_SANITIZERS "Enable address and undefined behavior sanitizers" OFF)
if(ENABLE_SANITIZERS AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(lab2 PRIVATE -fsanitize=address,undefined)
    target_link_options(lab2 PRIVATE -fsanitize=address,undefined)
endif()

include(ProcessorCount)
ProcessorCount(N)
if(NOT N EQUAL 0)
    set(CMAKE_BUILD_PARALLEL_LEVEL ${N} CACHE STRING "Number of parallel jobs for build")
endif()

# Output directories
set_target_properties(lab2 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

if(WIN32)
    set_target_properties(lab2 PROPERTIES OUTPUT_NAME "lab2")
endif()