Took me a few hours to figure out the solution, which is a dp method.\
The difficulty lies in how to figure out the relationship between dp[i] and dp[i + 1].\
My definition of dp is {total number of substrings of S.substr(i), number os substrings starts with S[i]}.\
Basically had to try running test cases to figure out the solution.

Here's a much simpler solution learned.\
https://leetcode.com/problems/distinct-subsequences-ii/discuss/192017/C++JavaPython-4-lines-O(N)-Time-O(1)-Space

The idea is total number of substrings is sum of substrings ends with 'a', 'b', 'c'...\
If we already have data above, adding one new char to the end will result in new substrings \
that should be added to dp[new char].