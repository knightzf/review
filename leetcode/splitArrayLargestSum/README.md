I spent about one hour to figure out the solution, basically a dp solution.\
Idea is dp[i][j] means min max subarray sum for nums[0] to nums[i] if divided into j subarrays.\
dp[i][j] is the min of all possible max of (min(dp[k][j - 1], sum nums[k + 1] to nums[i]))

There's smarter solution using binary search.\
The idea is the value we look for are between max of all nums and sum of all nums.\
Each time we try a target number to see if it's possible to divide nums into m sections by making each subarray\
with sum as close to target number as possible.
