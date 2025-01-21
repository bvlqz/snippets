cmake_minimum_required(VERSION 3.10)
project(NTPClient)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system)

add_executable(ntp_client main.cpp ntp_client.cpp)
target_include_directories(ntp_client PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(ntp_client PRIVATE Boost::system)
