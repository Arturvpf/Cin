Bellman-Ford algorithm:
Let G be a weighted graph and v ∈ V (source), finds the shortest path
from v to all other nodes in V
Bellman-Ford algorithm: can be used onweighted graphs with negative cycles

Time efficiency in Θ(| V || E |) = Θ(| V |3), since | E |∈ O(| V |2)


Floyd-Warshall algorithm
Let G be a weighted graph, finds the shortest path between all pairs of
nodes in G
All-pairs shortest paths
can be used on weighted graphs with negative weights (but no negative cycles)

Time efficiency in Θ(| V |3)