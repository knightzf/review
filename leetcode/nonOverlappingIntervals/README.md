The learned solution is a greedy solution which isn't easy to find out and hard to prove.

A better solution I think is a dp algo.\
Even though the time comlexity if O(N^2).\
The idea is simple, use dp[i] to mean max number of non-overlapping intervals that ends in intevals[i].\
Which needs to check all previous dp values that are not overlapped with current interval.

1/9/2021\
The idea is sort by end time and find out maximum number of non-overlapping intervals.\
The reason to sort by end time is basically we want to choose interval that ends earlier so that it's possible to place more intervals afterwards.
