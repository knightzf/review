This problem is by all means dfs.\
However the search can be tricky in terms of complexity.

My first attempt is to try all possibilities for each number (add or skip), however the complexity grows too quickly.

The learned solution, on the other hand, did pruning by only looking at sum of n numbers where n can be a possible result array length.\
That makes the search space drastically smaller.

Good lesson learned!
