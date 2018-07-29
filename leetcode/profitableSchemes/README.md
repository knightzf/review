Spent much time on this problem.\
First reaction, dfs, which works but unfortunately timed out.\
After thinking for long time I found this is essentially the Knapsack problem variation.\
However we want to find profits that are larger than P, which could be a lot of them.\
My accepted solution is to record each of them at each group which works but surely slow.

Looked at discussion, people are using 2d dp solution which I also thought about.\
The key here is to record counts with profits >= G at index G. Very clever!
https://leetcode.com/problems/profitable-schemes/discuss/154617/C++JavaPython-DP
