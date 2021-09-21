cmake_minimum_required(VERSION 3.20)
project(mindflayer_usb)

set(CMAKE_CXX_STANDARD 17)
add_definitions("-std=c++17")

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

add_executable(mindflayer_tentacle src/main.cpp)
target_link_libraries(mindflayer_tentacle ${CONAN_LIBS})