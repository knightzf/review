Spent a lot of time on this.\
The hard part is we only want to have unique palindromes which makes deduction hard.\
Then I figured in the end we only need to consider pair of chars that are farthest apart.\
As a result my first solution is dfs, which is easier to understand.\
Which leads to my second solution which is dp, however it took me much more time to get it right.\

Solution in discussion are similar, there's a dp solution which I also thought about,\
basically split total value into values from 4 pairs and it's much eaiser to understand.
https://leetcode.com/problems/count-different-palindromic-subsequences/discuss/109514/C%2B%2B-O(N2)-time-O(N)-memory-with-explanation