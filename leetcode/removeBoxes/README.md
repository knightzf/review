This is a very special problem.
https://leetcode.com/problems/remove-boxes/discuss/101310/Java-top-down-and-bottom-up-DP-solutions/149645

1. The normal dfs solution is easy to come by, however its complexcity is factorial which for 100 items is too large.\
2. I tried a dp solution, basically try to find dp[i][j + 1] assuming if we know dp[i][j]\
3. The above problem is non-trivial if we boxes[i] and boxes[j] are the same because you don't have a subproblem with known result.\
4. Instead you'll need to find all possible situations, i.e. boxes[j] can join boxes[i] in the end, but what about all the numbers in the middle?\
5. It's very hard to find solution to above problem.\
6. The learned solution is different in terms of it changes the dp definition.\
7. Directly define dp[i][j] is not a self-containing recursive problem because a states depends on extra information.\
8. The core of the problem is what happens in the middle and it feels like a N^2 dp type problem.\
9. The solution is to change dp definition to include the extra information (number of elements in the left that are same as boxes[i])\
10. By having this information, it can be split into smaller subproblems that can be solved without extra information.\
11. It's very easy to think too much into such problem because there's so many possibilities and you tend to look for some perfect greedy solution.\
12. Instead the key idea is if we want to connect all the items on the left to some element between i and j, we simple calc out the subproblem from i + 1 to m.\
13. What about if we join all items in the middle that are same as boxes[i]?\
14. It's also covered by the above definition if you think through.

I've learned a lot from this problem and learned a lot by talking with Haoting.
