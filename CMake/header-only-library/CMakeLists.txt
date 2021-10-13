CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

add_library(HeaderOnlyLibrary INTERFACE)

target_include_directories(
    HeaderOnlyLibrary
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)