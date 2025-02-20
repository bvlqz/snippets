# Graph Theory

> aka networks

```

(a)-(b)
 | /   \
(b)-(e)-(c)


(x) -> Vertex / Node
 -  -> Edge

```
* **Dense graph**: A graph with lots of edges in relation to the number of vertices (recommended to use an adjacency matrix)
* **Sparse graph**: A graph with few edges in relation to the number of vertices (recommended to use an adjacency list)
* **Path**: A sequence of vertices
* **Cycle**: A path in which the starting vertex is also the ending vertex

# Application / Problems
- Navigation systems
- Data transmission
- Social networks
- A mesh is a type of graphs

# Types

* **Undirected Graph** (Unordered): Edges have no orientation.
```
(a)─(b)
     │
    (c)
```

* **Directed Graphs** (Digraph): Edges have orientations.
```
(a) ─► (b) ◄─ (c)
        ▲
        │
       (d)
```
* **Weighted Graphs**: Contains a certain weight to represent an arbitrary value in each edge.
```
      2         -4
(a) ◄───► (b) ◄──── (c)
           ▲
           │5
          (d)
```

* **Trees**: Undirected graph with no cycles.
* **Rooted Tree**: A tree with a designated root node.
* **Directed Acyclic Graphs** (DAGs): Directed graphs with no cicles. Used to represent structures with dependencies.
* **Bipartite Graphs**: Vertices can be split into two intependent groups U, V such that every edge connects between U and V.
* **Complete Graphs**: There is a unique edge between every pair of nodes.


# Common questions
- Is the graph directed or undirected?
- Are the edges of the graph weighted?
- Is the graph likely to be sparse or dense with edges?
- Should I use an  Adjancency Matrix, Adjancency List, an Edge List or other structure to represent the graph efficiently?

# Representing Graps

## Adjancency Matrix
* Edge weight lookup `O(1)`
* Requires `O(V²)` space
* Iterating over all edges takes `O(V²)` time
```
   A  B  C  D
A [0  4  1  9]
B [3  0  6 11]
C [4  1  0  2]
D [6  5 -4  0]
```
Node `A` can reach:
* Itself with cost 0
* Node `B` with cost `4`
* Node `C` with cost `1`
* Node `D` with cost `9`

## Adjancency List
*  Edge weight lookup `O(E)` 
```
A -> [ (B, 4), (C, 1) ]
B -> [ (C, 6) ]
C -> [ (A, 4), (B, 1), (D, 2)]
D -> [ ]
```
Node `C` can reach:
* Node `A` with cost `4`
* Node `B` with cost `1`
* Node `D` with cost `2`

## Edge List
*  Edge weight lookup `O(E)` 
```

[ (C,A,4), (A,C,1),
  (B,C,6), (A,B,4),
  (C,B,1), (C,D,2) ]

(u, v, w)

u = Where an Edge is coming from (Node / Vertex)
v = Where an Edge is going to (Node /Vertex)
w = Weight
```
Node `C` can reach:
* Node `A` with cost `4`
* Node `B` with cost `1`
* Node `D` with cost `2`

# Traversing a graph


## Depht First Traversal / Depht First Seach (DFS)
`O(Vertices + Edges)`

Following a path until you exhaust all the vertices in the graph (until you can go no further, then you backtrack untill you can continue).

Recommended to use a Stack.

**DFS can be used to:**
* Compute a graph's minimun spanning tree
* Detect and find cycles in a graph
* Check if a graph is bipartite
* Find strongly connected components
* Topologically sort the nodes of a graph
* Find bridges and articulation points
* Find augmenting paths in a flow network
* Generate mazes


## Breadth First Traversal / Breadth First Search (BFS)
`O(Vertices + Edges)`

Start with the first vertex and tries to visit all the vertices as close to this vertex as possible.

Useful when finding the shortest path on unweighted graphs

Recommended to use a queue.