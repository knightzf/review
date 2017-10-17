It feels really hard, I knew it's a dp problem but couldn't figure out the formula.

It turns out the key is the value of dp[i][j] is min of dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j] if word1[i - 1] != word2[j - 1]

Thanks Sheng for the hint
