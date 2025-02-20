
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

add_library(
    Graphs
    Graph.h
    Graph.cpp
    Node.h
    Node.cpp
    Edge.h
    Edge.cpp
    Dijkstra.h
    Dijkstra.cpp)


add_executable(GraphDemo demo.cpp)

target_link_libraries(GraphDemo PRIVATE Graphs)