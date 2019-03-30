It took me a few days to figure out this solution.\
The key is how to understand "A song can only be played again only if K other songs have been played."\
Essentially for any length K sublist, there is no duplicate.\
In other words, when list size is > K, the possible choices are N - K.\
I spent more time thinking of cases to place missing songs as it requires to have each song played at least once.\
The result is very efficient but not as clean.

Checked discussion and the dp solution is very clean. Brilliant!\
I'm still very inmature in algorithms.

dp[N][L] = N * dp[N - 1][L - 1] + dp[N][L - 1] * (N - K)