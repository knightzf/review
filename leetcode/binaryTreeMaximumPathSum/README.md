My solution, although failed one test on leetcode, returned correct value in my local run.

That aside, my solution is basically first convert tree into a graph and do a dfs search for each node pair a, b with a cache that stores the values already figured out.


The learned solution is much smarter, as the author pointed out, a max path is from a to one of its parent node and then go down to point b.

So the recursion function only needs to calculate the max sum from one node down. While keep track of the max sum. Very brilliant!
