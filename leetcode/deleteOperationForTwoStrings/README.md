My solution is not the optimal, but essentially it's recursion with memorization that calculates number of\
longest common subsequence of two strings from i and j.\
The idea is fine but requires using extra set to look up matching characters.

Learned dp solution converts this problem into finding longest common subsequence problem.\
Then it uses dp to find value we want. After that the answer is obvious.\
I spent some time trying to think of the dp conversion formula.\
It's very easy for me to think too much into different situations which becomes difficult.\
Actually it's pretty simple. Only special case is when word1[i] and word2[j] are the same.\
Otherwise it's either dp[i - 1][j] or dp[i][j - 1]
