cmake_minimum_required(VERSION 3.10)
project(subimage_feature)

set(CMAKE_CXX_STANDARD 11)
set(CUDA_USE_STATIC_CUDA_RUNTIME OFF)

find_package(OpenCV REQUIRED)
find_package(PCL REQUIRED)

include_directories(
        ${PROJECT_SOURCE_DIR}/include/
        ${OpenCV_INCLUDE_DIRS}
        ${PCL_INCLUDE_DIRS})

add_executable(
        subimage_feature
        main.cpp)

target_link_libraries(
        subimage_feature
        ${OpenCV_LIBS}
        ${PCL_LIBRARIES})
