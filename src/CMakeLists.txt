# We might support earlier versions, too, but try to use a more recent one.
cmake_minimum_required (VERSION 3.8)

project(dds2png)

set(dds2png_sources
    util/GitInfos.cpp
    Version.cpp
    main.cpp)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_definitions (-Wall -Wextra -pedantic -pedantic-errors -O3 -fexceptions)

    set( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -s" )
endif ()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dds2png ${dds2png_sources})

if (NOT MSVC)
  # link static library for std::filesystem on GNU C++ compiler
  target_link_libraries(dds2png stdc++fs)
endif ()

# find DevIL
find_package (DevIL)
if (DevIL_FOUND)
  include_directories(${IL_INCLUDE_DIR})
  target_link_libraries (dds2png ${IL_LIBRARIES})
else ()
  message ( FATAL_ERROR "DevIL was not found!" )
endif (DevIL_FOUND)


# create git-related constants
# -- get the current commit hash
execute_process(
  COMMAND git rev-parse HEAD
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# -- get the commit date
execute_process(
  COMMAND git show -s --format=%ci
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_TIME
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

message("GIT_HASH is ${GIT_HASH}.")
message("GIT_TIME is ${GIT_TIME}.")

# replace git-related constants in GitInfos.cpp
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/util/GitInfos.template.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/util/GitInfos.cpp
               ESCAPE_QUOTES)
