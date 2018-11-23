My first intuition, find all starting indexes and check until we can find a match.\
Learned a dp solution from discussion and implemented it myself.\
The idea is dp[i, j] means substring start index for substring ends at S[j].\
So if S[j] == T[i], we can then have dp[i][j] = dp[i - 1][j - 1].