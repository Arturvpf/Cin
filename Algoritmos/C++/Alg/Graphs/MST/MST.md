Minimum-cost spanning tree (MST):
Let G be an undirected connected graph, an MST is a connected
acyclic subgraph (i.e, a tree) that contains all vertices of G. If G
has weights, an MST is the tree with the smallest weight (sum of all weights on all its edges).


Prims algorithm:

Constructs an MST through a sequence of expanding subtrees
Initial subtree consists of a single arbitrary vertex
On each iteration, expands the current tree in a greedy manner
by attaching to it the nearest vertex not in this tree
Nearest vertex: a vertex no in the tree connected to
a vertex in the tree by an edge of the smallest weight
Algorithm stops after including all vertices
Prim’s algorithm: similar to the Dijkstra’s algorithm
Can be used on weighted graphs with
negative weights (and also with negative cycles)

Time efficiency (same as of Dijkstra’s)
Matrix with no heap: Θ(| V |2)

List with heap: Θ((| V | + | E |) log | V |)


Disjoint subsets:
Essa estrutura é usada para gerenciar um conjunto de elementos particionado em subconjuntos disjuntos, ou seja, subconjuntos que não compartilham elementos entre si.  usado em algoritmo de kruskal


Kruskal’s algorithm:
Another greedy algorithm
Initially, n = | V | MSTs
On each iteration, chooses an edge of G with the smallest weight
that unions two MSTs (i.e., without introducing a cycle)
Time efficiency: similar to Prim’s
Prim: best for dense graphs
Kruskal: best for sparse graphs



