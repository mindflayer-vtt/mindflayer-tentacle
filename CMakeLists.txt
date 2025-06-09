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

add_executable(mindflayer_tentacle src/mindflayer/main.cpp src/mindflayer/input/UserInputDevice.cpp src/mindflayer/input/UserInputDevice.h src/mindflayer/controller/Controller.cpp src/mindflayer/controller/Controller.h src/mindflayer/server/ServerConnection.cpp src/mindflayer/server/ServerConnection.h)
target_link_libraries(mindflayer_tentacle ${CONAN_LIBS})