I think it's more valuable to find blind spots in my thinking process.\

For this problem, it's not hard to see that we can calculate final state of each person's balance easily.\
Then with some positive and some negative, we want to find the least moves the balances so that everyone has 0 balance.

How to do it? Natually BFS, but how to know what is the optimal move?\
The conclusion here is to make current balance 0 by offsetting to another person's balance.

As a BFS problem, we need to know the states of each move which is hard to write recursively.\
Also if we use two vectors to store positive and negative balances, the state becomes even harder to keep track of.

The learned solution is to use DFS instead of BFS and keep track of number of minimum moves.\
Also it uses one vector to store positive and negative balances.\
Each time we find a non-zero balance, only go right to find another non-zero balance of different sign.\
This reduces the search space but still it's a worst case O(N!) solution.

On another hand, it's similar to the backpack problem, that's probably the other reason I struggled a lot.

Blind spots:
1. BFS to DFS
2. Two vectors vs one vector
