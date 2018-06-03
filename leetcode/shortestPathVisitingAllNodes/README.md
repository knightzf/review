I didn't find a solution during contest.

My thought process:\
1. Go from each node, find length to visit all nodes, then find the shortest.\
2. This is a dfs solution which is not efficient.\
3. However at first I couldn't find a good way to write out the solution.\
4. The problem was it allows going back (visit one node more than one time.)\
5. I tried to use a visited array which at first contains number of connections for each node.\
6. However it fails to handle the case where it goes from 0 -> 1 and then 1 -> 0.\
7. That's because for dfs, we need to keep track of temp state which is hard if we need to count the connections.\
8. After the contest, I changed the model so that each node has a set of connected nodes.\
9. For each step, we take out the node that we go to.\
10. The assumption is you won't visit the node more than twice (0 -> 1 -> 0 -> 1 makes no sense.)
11. However it times out for longer inputs.

Learned solution:\
1. The key point is to define the dp based on state (bit mask) and current idx.\
2. so that we can use a queue to run a bfs solution.\
3. Given limited number of nodes, use state bit mask is a potential solution.\
4. So it's still a bfs but with memorization because you can get to same state from different paths.
