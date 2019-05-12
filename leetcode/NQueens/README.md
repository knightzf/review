Backtrack problem.

My solution is not very efficent. It can be converted into a recursion call instead of using a queue for bfs search.

4/19\
Instead of using a full board, we only need to record n points.\
Also used dfs with aggresive pruning instead of bfs.\
To determine whether a new point is valid, in discussion there's a way\
to basically record for a given i, j, whether the column, 45 degree diagonal\
and 135 degree diaonal already have queen. This is doable because there is\
only limited number of diagonals for given n.
