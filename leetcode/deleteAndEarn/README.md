I had the feeling it's a dp question looking at it because there's no algo that can tell you directly which ones to remove in order to get max value.

However I failed to find the dp relationship. My first try is basically a comprehensive try of all possible values, which times out when number of elements are a little larger.

Checking other people's solution, the idea is

dp[i] is either

    dp[i - 1] //count[i] is either 0 or removed as the effect of removing its neighbor so count[i] doesn't count

        or

    dp[i - 2] + i * count[i]  //count[i] is removed to take credit, so dp[i - 1] doesn't matter any more.


The dp logic, not very straightforward even after reading the solution, is a little tricky
