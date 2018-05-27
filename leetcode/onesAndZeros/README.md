It's a variation of knapsack problem.

Thought process:\
1. Each string is either in the result strings or not, which is easy to write. But it's a O(2^N) solution.\
2. 3d dp solutions.
* define dp[i][j][k] as the max number of strings can be constructed by i 0's and j 1's that ends in s[k].
* but we need to look at all possible dp[i - x][j - y][1,2...k - 1] where x and y are # of 0's and 1's in the s[k].
* can we skip the last loop?
* yes! we can change the definition to be max number of strings can be found from s[0] to s[k].
* With the new definition, we don't have to look at all possible values, only check at k - 1 dp value.
* this is because we default dp[i][j][k] to be dp[i][j][k - 1] if s[k] can't be included

Looked at discussion, there's a solution which is also 3d dp, however it loops through list of strings\
and then go over i and j from bottom right to top left to find its value.\
I think it's similar to my solution possibily a bit more efficient due to less number of loops.\
Complexicity in time is still the same.
