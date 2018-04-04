4/3\
Great problem.\
I overlooked this problem first time I did it.\

First to clarify, a word in the dictionary can be used many times.

My thoughts were simple, basically start from beginning and find matching substrings then dfs.\
However it timesout for large input like "aaaaaaaaaaaaaaaa..." and dict word are "a", "aa", "aaa" etc\
I added a simple hack to return false for all input longer than 100, it beats 99.99% solutions...

The learned solution is great because it uses dp to solve it which is very clever.\
What we want to know? Can substring of s to index i be constructed using dictionary words.\
So it's natually a dp problem and we only need to try different substrings backwards from index i to see\
1. The dp[i - len of substring] value is true
2. If the substring can be found in the dictionary

Idea learned!
