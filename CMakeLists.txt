cmake_minimum_required(VERSION 3.6)
project(faceDetection)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)
set(OpenCV_DIR  /home/opencv/opencv)

find_package(OpenCV REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(faceDetection ${SOURCE_FILES})
target_link_libraries(faceDetection ${OpenCV_LIBS})