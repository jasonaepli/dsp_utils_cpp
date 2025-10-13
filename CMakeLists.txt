cmake_minimum_required(VERSION 3.11.3)

#set(CMAKE_CXX_STANDARD 17)
project(dsp_utils)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lliquid -pthread")

# Find all executables
#file(GLOB project_SRCS waveform/*.cpp)
#file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE project_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
# Add project executable
add_executable(dsp_utils ${project_SRCS})
