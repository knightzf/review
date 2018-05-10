The learned solution is a greedy solution which isn't easy to find out and hard to prove.

A better solution I think is a dp algo.\
Even though the time comlexity if O(N^2).\
The idea is simple, use dp[i] to mean max number of non-overlapping intervals that ends in intevals[i].\
Which needs to check all previous dp values that are not overlapped with current interval.
