# We might support earlier versions, too, but try to use a more recent one.
cmake_minimum_required (VERSION 3.8)

project(dds2png)

enable_testing()

# Recurse into subdirectory for the main executable.
add_subdirectory (src)

# Recurse into subdirectory for tests.
add_subdirectory (tests)
