I spent a lot of time trying to solve this problem by removing bricks one by one.\
But will always fail on edge cases.\
The difficulty is to find out the dependency relationship between bricks, as there can be bricks\
connecting to top row in an overlapping manner. Thus after removal it becomes really hard to properly\
update this dependency, need to think about connection from 4 directions, as well as multiple dependencies.\
Also how to propagate after deletion is also very tricky.

Also a simple way is just to find connected bricks after each deletion but too slow.

Learned solution is brilliant in a few ways:\
First it thinks the problem from end state to start state, by looking how many bricks will it connect to\
top row by placing the removed bricks back to the grid.\
Second it uses union find to also collect number of children for each brick by combining children number when\
doing a union. I've seen this trick in other problems.

When I learned the idea of starting from end, I implemented both bfs and dfs solution, which is a little tricky\
about the details, but the idea is nothing special.

https://leetcode.com/problems/bricks-falling-when-hit/discuss/193781/UnionFind