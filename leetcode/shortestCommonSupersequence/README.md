I came up with the solution to find shortest common string for any i,j, however it exceeds the memory limit.\
Learned solution is to find the longest common subsequence for two strings, using a similar dp solution.\
After that we can use this information to basically use the lcs and put the chars not in lcs in to final result.

The lesson learned here is how to convert this problem into an existing problem, the direct solution may not be\
the best.