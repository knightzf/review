First reaction is BFS, which works, but too slow due to the fact that with growth of size, one node can be accessed via exponential number of paths.

Then it occurs to me that path to each node is the sum of path to its two accesible previous nodes, then we only need to define the boarder values and it becomes very easy.
