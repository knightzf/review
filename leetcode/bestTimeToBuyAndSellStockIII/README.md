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
