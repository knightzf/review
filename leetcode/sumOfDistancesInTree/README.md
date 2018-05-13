My initial thought, do bfs from each node and know the distances.\
It works but not ideal.

The learned solution is much better since it only needs to run two dfs instead of N bfs.\
What is the idea?
* First bfs we find count of subtree nodes for each node, in the process we can also find the sum of distance of node
* After first bfs is complete, now only the root (node 0) has correct sum of distance
* One thing to mention res[root] += res[i] + count[i], why it that?
* Because for node root, we know sum of distance of its child i, we'll add one extra step for each node in i's subtree, which is the count[i]
* Next bfs, we want to find out sum of distance for all other nodes
* In order to do that, when we move to node i from root, there's count[i] nodes that are 1 step closer to i and N - count[i] nodes 1 step further to i
* Then the equation is res[i] = res[root] - count[i] + N - count[i]

This is really in-depth understanding of the problem and that's what I miss.
