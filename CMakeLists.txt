cmake_minimum_required(VERSION 3.5)
project(learncv C CXX)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
MESSAGE(STATUS "opencv includes: ${OpenCV_INCLUDE_DIRS}")

add_executable(imgshow imgshow.cpp)
target_link_libraries(imgshow ${OpenCV_LIBS})

add_executable(video video.cpp)
target_link_libraries(video ${OpenCV_LIBS})

add_executable(camshift camshift.cpp)
target_link_libraries(camshift ${OpenCV_LIBS})

add_executable(linear_filter linear_filter.cpp)
target_link_libraries(linear_filter ${OpenCV_LIBS})

