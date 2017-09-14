The key is: how to find shortest path between two points in a matrix?

The solution is a BFS, basically start from one point, add all valid unvisited neighbors to the queue and loop until it sees the detination point.

Why it works? Every loop increase the count by 1 and it checks all possible neighbors, that means if at step N it meets desination, it must be the solution that exhausted all possible N*4 neighbors.
