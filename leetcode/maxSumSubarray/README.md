At least two ways to solve the problem.

1. I've never seen this problem before so it took me a while to find this strategy. The core idea is if there's a subarray from index m + 1 to n which has max sum, the max sum is equal to sum[0, n] - sum[0, m].

    The only tricky part left is there are some special cases.

        a. sum[0, n] == 2 and sum[0, m] == -1, so the max sum is 2 - (-1) = 3. This is very obvious.

        b. sum[0, n] == -3 and sum[0, m] == -2, what is the max sum? It's actually -3 - (-2) = -1

    So the solution is not always maxSum - minSum, rather it's a little dynamic.

    Initiate minSum = 0

    When currSum - minSum > result, result = sum - minSum;

    When currSum < minSum, minSum = currSum;

    For other cases, we don't touch result or minSum.

    Why setting minSum to 0 at the beginning? Because only if minSum is less than 0, subtracting minSum would increase max sum.

    It's a little tricky in the above logic and it took me quite some time to understand.


2. Apparently this is a classic dp problem and it's a good opportunity to learn dp. Leetcode marks this problem as easy is a little unfair unless most people already know this problem.

    Idea is simple, if we find such a subarray, it must end with a value nums[i].

    We denote dp[i] as the max sum of subarrays end with dp[i].

    It's then easy to deduce dp[i + 1] is dp[i] + nums[i + 1] if dp[i] > 0 or nums[i + 1] otherwise

    It basically one more check than the classic fibonacci problem.

