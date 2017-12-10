My solution

1. Find the node using bfs
2. Check if the node is a leaf, return if it's true
3. Find the cloest child leaf from current node using dfs
4. Backtrace parent nodes and find first child leaf of all parents
5. Now we can find out which is the closest

Looking at discussion

Popular approach seems to be converting tree into undirected graph and find the first leaf using bfs
