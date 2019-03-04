I spent a whole day's time on this problem.\
First dfs which is factorial time complexity.

Then got a hint this is n^3 dp problem.\
Tried to start with K = 2 which is an easy case.\
However to generalize to K, took me very long time.

A few things:\
1. It's relatively easy when total number can be moved to one pile.\
The new K - 1 additions can be incorporated into existing piles which is a sub problem.
2. What to do when the total number can't be moved to one pile? \
I first ignored this caes but it's obviously wrong.\
3. Then I tried to find the value for case 2, which turns out to be essentially very similar to case 1.

Read this from discussion, it's very clean explanation that breaks down problem into\
subproblems, which is diffrent from my solution but much easier to understand, besides it\
defines the deduction function perfectly, even the solution is not the most efficient.\
I tried to start from bottom up which is really hard to think of, bottom down is easier.
https://leetcode.com/problems/minimum-cost-to-merge-stones/discuss/247657/JAVA-Bottom-Up-%2B-Top-Down-DP-With-Explaination

