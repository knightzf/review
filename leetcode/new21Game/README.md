This is a very good question which exposed my blind spots in thinking process.\
I only thought of step by step, means first steps we can get to 1, 2, 3... each with 1/W probability.\
Then start from there we go to next step, which grows exponentially and will not work.

But if we think of probability of getting at i is dp[i], which counts all possible paths of getting here.\
Then we can find out dp[i + 1] can be achieved from dp[i], dp[i - 1], dp[i - 2] ... by one extra step.\
This will be a O(N^2) type dp solution.

However we can go further by definiting dp[i] as the sum of probabilities of getting to 1, 2, 3...i.\
dp[i] - dp[i - 1] = (dp[i - 1] - dp[i - W - 1]) / W\
What does it mean? the probability of getting i (dp[i] - dp[i - 1]) is sum of getting i - 1, i - 2... i - W and one step from there.\

This is crucial in solving this problem.

Another detail is we want to know the probability of getting a final value <= N.\
It's not hard to see the maximum possible value is K + W - 1.\
So we find all dp[i] from i = 0 to K + W - 1\
And we will know the possiblity of having a final value > N and <= N.

When i is larger than K, from the formula above we will have counted the possiblities of cases we don't want.\
For example from i - 1 to i where i - 1 is also larger than K.\
Because in our question it won't get any future if it's already >= K, so we need to subtract these possibilities.\
We'll need to substract between K to i - 1 thus (dp[i - 1] - dp[K - 1]) / W.


My thinking blind spots:
* Step by step vs state
* Single state to summation
