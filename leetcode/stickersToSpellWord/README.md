My first thought
1. Get map of all substring from all stickers

2. Recursively find all possible combinations for given target

3. Check min stickers for each combination to find the min


Step 3 isn't complete. Given the learned solution, step 3 is probably doable but still feels tricky.

Learned solution is a very different approach.

https://discuss.leetcode.com/topic/106273/c-java-python-dp-memoization-with-optimization-29-ms-c

1. Create histogram for letter a to z for each ticker.

2. Recursively find min number of tickers needed for any substring of target.

3. DP logic is not linear like dp[i] from dp[i - 1].
   It's try to apply ticker to target and get resulting string consisted of remaining letters.
   So this recursion will yield dp[some string] then get dp[target].
