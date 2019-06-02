I started off dfs and it's difficult in a few ways.\
1. Time complexity is O(N!).\
2. Have to use an extra data structure to keep track of state which due to the nature of the operation is hard.\

Thought for long time without success and checked the results.\
What I didn't realized is this problem is essentially putting numbers into 2 bags because the operation\
is exactly doing + or - among the numbers.

Then it's a knap-sack problem. And the solution isn't that straightforward either.\
Basically we are trying to find the bag with smaller sum which is at most 1500.\
How do we know if each number is possible?\
Then it's a dp solution to find this information.\
Really frustrated by this problem, need to keep learning.