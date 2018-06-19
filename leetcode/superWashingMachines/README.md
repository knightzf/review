I spent almost a day thinking about this problem.\

1. Given the size of list, any dfs/bfs solution won't work.\
2. Besides, each time m is undefined and direction is undefined which causes too much uncertainty.\
3. Tried to find the deeper fact of the problem.\
4. If we move one each time, it's definitely going to have a solution however can't deduct anything useful from the brute force approach.\
5. Then I think of if we know the sum as of i, we know if we are more than we need or we need from right side.\
6. Then tried to look at each i where machines[i] is larger than sum and see how many moves we need at each i.\
7. Then realized from test if i,j are adjacent and there are difference cases which direction they can move.\
8. Then I tried to group continuous indices if they are more than avg which still fails for some of cases.\
9. Finally checked the discussion, the solution is actually quite similar to my thoughts.\
10. It considers number of moves at each index and then the max of them is the answer we need.\
11. The only trick left is if we need to move from this index to both left and right, it can't be done at the same time.

Conclusion:\
My approach was in the right direction however went more into greedy approach and that's why I didn't find the solution.\
Need a little more global perspective, what the problem actually means.
