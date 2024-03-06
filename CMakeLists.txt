cmake_minimum_required(VERSION 3.16)
project(nsloader)

enable_testing()
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(third_party/spdlog)
add_subdirectory(src)

add_library(common INTERFACE)
target_compile_features(common INTERFACE cxx_std_20)
target_include_directories(common INTERFACE include)
