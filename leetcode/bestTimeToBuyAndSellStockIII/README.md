I misunderstood the problem at the beginning, I thought you just need to find the increasing subsets and find the two largest diffs.

However it's different because the number of transactions are limited. You can find the subsets but a cross subset transaction might give you larger results.

So back to dp solution. It's very easy to define dp[i][j] as max profit for at most i transactions given prices 0 to j.

But it takes a genius to find the deduction formula.

dp[i][j] is the max of

    dp[i][j - 1] // Do nothing at j

        and

    dp[i - 1][k] + max(prices[j] - prices[k]) where k = 0, 1, 2...j-1 //meaning we sell at j


Now the thing that confused me a lot is why we can use prices[k] given we are using dp[i - 1][k]?


Because there are two possibilities

1. dp[i - 1][k] doesn't sell at k, which is fine for above formula

2. dp[i - 1][k] sells at k, which makes it possible to be selling at j and buying at j again, which violates the restriction.

   But if we sell at j and buy at j, that essentially means we did nothing, which is a valid case.

3/19\
Looked at the problem again, I knew it's a dp problem but the transition formula I came up didn't seem to work.\
After inspecting the numbers, it turns out you need to properly set initial value.\
Looked at previous learned solution, it's actually quite tricky, I'm still not 100% understanding it.


5/19\
Did it again using two dp arrays, which isn't terribly efficient however very\
clean to understand. \
There's a better solution in discussion which is also very easy to understand.\
Just need to set the initial valus right.
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39611/Is-it-Best-Solution-with-O(n)-O(1).
