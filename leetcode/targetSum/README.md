Knew it's a dp problem because dfs grows exponentially even with some pruning.

I spent much time figuring out the second dimension range of the dp matrix, turns out it's not that complicated.

There is a smarter solution in the discussion\
https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C++-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation

The observation is based on the fact that \
```C++
                  sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
                       2 * sum(P) = target + sum(nums)
```

The problem is then converted into find number of subarrays so that sum equals to (target + sum of nums) / 2.\
The solution is a 1D dp method which only works for positive numbers.
