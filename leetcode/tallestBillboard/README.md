I found this problem very similar to knapsack problem.\
However it's 3^N complexity as each rod can be placed in group 1, group 2 or none.\
I only came up with a dfs solution that simplies the problem a bit however I need to\
check all numbers in the possible range to know the largest which slows it down a lot.

Leanred solution is better because first it's dp, the defintion of dp is tricky.\
dp[diff] = a means there's a pair of numbers (a, a + diff) where a is the max we can find.

If we have the dp info given rodbs from 0 to i, if we add a new rod, there's a few case\
1. New rod can be added to longer side so that the dp[diff + rod] can possibly update.\
2. New rod can be added to shorter side so that dp[abs(diff - row)] can possibly updated.

It took me very long time to understand the above logic, the key is to image ther's already\
a pair, now we have a new rod, it can be placed in one side or discard (in which case nothing changes.)