
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

add_library(HashTables INTERFACE)

target_include_directories(
    HashTables
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(HashTableDemo demo.cpp)