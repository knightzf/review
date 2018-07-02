Again a great question.\
https://leetcode.com/problems/burst-balloons/discuss/76228/Share-some-analysis-and-explanations

My initial idea is very simple, typical back tracking which I know is very slow.\
There must be better solutions, but how?

From the discussion, if we want to divide and conqur, however after removing a value, the two neighbors are now next to each other.\
Thus they cannot be divided.

Then the brilliant idea is what about we divide by the last point to remove? In that case, left and right sides are completely separated.

The most critical point is how to define dp[i][j]?\
It's defined as the max number of coins from i to j without popping i or j (they are boundaries.)

For each dp[i][j] we need to try all possible last pop points between i and j.\
So we use a size K to denote the length between i and j, start from 2. Rest is natual.

7/1\
This is after encountering a similar problem remove boxes\
This type of problem can be solved recursively but a direct divide will result in two sub problems that depend on each other.\
This type of problem is not self containing thus impossible to find a recursive solution.\
However the key is we can change how we define the problem to include extra information so that it becomes self containing.\
Here the extra information is left and right bound index, thus the dp becomes dp[i, j, leftIdx, rightIdx].\
There's another key is instead of divide the problem by the first move, we divide it by the last move so two subproblems no longer depend on each other.
