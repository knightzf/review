This problem isn't hard, I thought for a while and couldn't find another solution other than dfs/bfs.

The surprising thing is dfs times out while bfs works.\
Normally dfs solves same problem faster than bfs because it doesn't need to store extra information in the queue.\
However in this case dfs runs so slow because it needs to exhuast all possible paths in order to find the minimum.\
On the other hand bfs will stop as soon as it finds one answer.
