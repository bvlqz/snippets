CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

add_library(LinkedLists INTERFACE)

target_include_directories(
    LinkedLists
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(LinkedListDemo demo.cpp)