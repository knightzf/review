Very difficult problem in my view. However Sheng and Qiaoyuan were able to figure out the answer themsevles.

If we only walk once, it's a very simple dp question.

Also it's not hard to see the second walk is just the same as first.

The difficulty is the first walk will eleminate cherries, which impacts second walk.

Weiming tried to just run two dps to find the max values and claimed the sum of two is the answer.

It doesn't feel right and I was able to find a counter example after discussion with him.

The example is

0 1 1 1 0 0 0
0 0 0 0 0 0 1
1 0 0 1 0 0 1
1 0 0 1 0 0 1
1 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 1 1 1 0

So it goes back to the 3d dp solution. Took me quite some time to figure out.

The definition of dp[i][j] is the max number of cherries First path goes down i steps and Second path goes doesn j steps given total number of steps.

Let me explain a bit, what we want to know? Max number of cherries after two path.

How many steps of each path? It need to go n - 1 steps down and n - 2 steps right, so total is 2n - 2.

How do we know dp[i][j] given number of steps 2n - 2? We start from total number of steps 1.

So it's a 3 layer loop.

For given step k, the coordinates of two points are [i, k - i] and [j, k - j]

Looking at step k - 1, possible cordinates of two points are [i, k - i - 1], [i - 1, k - i] and [j, k - j - 1], [j - 1, k - j]

The corresponding dp values are dp[i, j], dp[i - 1, j], dp[i, j - 1] and dp[i - 1, j - 1] for k -1 steps

The rest are details and some corner cases.



