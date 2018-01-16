It is definitely a dp problem.

The issue is how to define the dp definition.

My solution is to denote dp[i] as the max value includeing nums[i].

So dp[i] is euqal to nums[i] + max(dp[i - 2], dp[i - 1] - nums[i -1])
