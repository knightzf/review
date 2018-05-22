Thought process:\
1. Similar to the problem did last night\
2. We can't afford finding all substrings, so it's likely to be a dp problem\
3. Then it's the definition of dp, dp[i] means number of substrings starting at index i\
4. I used two dp arrays, one to store dp above and the other to store max cnt starting at a, b, c...\
5. It works but not the optimal\
6. The best solution is to keep track of max substring len and only update max cnt when it's larger than current value\
7. The solution is very neat and I am just about one step from there
