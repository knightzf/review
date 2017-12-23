First impression: recursion

Then it appears to be too many recursions which will not scale if input grows

But recursion is usually a good indication of dp

The only thing is to define the meaning of dp

I use dp[i][j] where i is index in the test string and j for the target string

and dp[i][j] means the number of subsequences at i and j

The logic to deduct dp[i][j]:

1. Border is easy, just look at the one before

2. When i == j means two strings are of same length, if s[i] == t[j] and dp[i - 1][j - 1] is not 0, it's dp[i - 1][j - 1] + 1

3. When i > j which is most of the case, if s[i] == t[j], look at dp[i - 1][j - 1] and dp[i - 1][j], otherwise it's same as dp[i - 1][j]
