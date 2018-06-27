I knew this problem could be solved by starting from 0s and gradually expand all all cells.\
However I tried to use normal dfs to solve the problem, only found it's hard to do so because:\
1. We don't want to recalc for the same cell so we use a visited matrix to check\
2. We need to look at top down left right neighbors but due to the visited check we may not able to get a result for some cells\
I ended up using the original thought which works but slow.

Checked discussion, there's better solution basically using dp in two loops.\
First loop only look at top and left cells from upper left to bottom right.\
Second loop only look at down and right cells from bottom right to upper left.
https://leetcode.com/problems/01-matrix/discuss/135746/Two-pass-dp-c++-O(mn)-beats-99.4

Why this works? It's obvious that a cell's value depends on its neighbors.\
But checking 4 neighbors at the same time cause more problems, plus it doesn't necessarily find the solution.\
Separating the logic into two steps gurantees a cell is updated at most twice which checks all 4 neighbors and \
also covers possible error by only checking up and left.
The first loop finds nearest 0 from top and left, the second loop finds nearest 0 from bottom and right.\
There's no chance a nearest cell is from both directions.
