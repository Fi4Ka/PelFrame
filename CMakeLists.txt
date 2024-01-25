cmake_minimum_required(VERSION 3.0)
project(PelFrame2)

set(OpenCV_DIR D:/opencv/build) 
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} PelFrame2/PelFrame2.cpp)

# Подключить OpenCV
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
