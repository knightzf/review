When I looked at this problem, I see two steps\
1. find repetitive continuous substrings\
2. check if encoding will make the string shorter

To find repetitive continuous substrings, I thought for a while, there's no easy way.\
My best idea was to find indices for each char a, b, c...\
and find if there's repetitive continuous substring from each index of a, b, c..

Then the problem remains we don't know which is the best way to encode it, couldn't think of a greedy method.

Looked at discussion, the solution is dp algo.\
dp[i][j] is defined as the shorted encoded string for s[i] to s[j] inclusive.

I first thought about it but couldn't see a formula from existing dp value to dp[i][j].\
It turns out the solution is a O(N^2) type dp, basically to see if any k between i and j so that\
(dp[i][k] + dp[k + 1][j]).size() < dp[i][j] (which is the substring itself at start)

Then for each substring s[i - j], we can try to see if there's repetitive substrings inside.\
We don't need to consider the case where s[i - j] can't be divided evenly because it's covered in the case above.\
This is also an O(K) check.

Blind spots of my thought process:\
1. Couldn't see the O(N^2) algorithm even this dp definition is unconventional\
2. Tried to think of a case to fit all but it can actually be divided into smaller problems.\
3. Point 2 is a typical divide and conqur algo.
