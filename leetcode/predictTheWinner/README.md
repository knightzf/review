Learned a lot from this question.\
1. My initial solution is a recursive solution which has this problem\
    P1 is guranteed to win means\
    There is a choice nums[0] or nums[n - 1] s.t. P2 is never going to win\
2. I tried to think of a dp solution however found it difficult to come up with a good dp definition

Looked at discussion, it's actually a problem from MIT algorithm class.\
If n is even, this problem doesn't require any dp any all.\
Why?\
We first find sum of numbers at odd indices and even indices, we know which is larger.\
For P1, he can choose all odd indices or even indices based on the knowledge above.\
Because he can always choose the odd index after P2 move.

For a more general case, which is also what I was thinking about.\
I also thought dp[i][j] to be max sum from indices i to j.\
But I also thought of another dimension of whether use is the one to move.\
It adds more complexity which I found hard to do.

In fact, the 3rd dimension is not needed, the transition formula isn't too hard once we write it down.\
I was almost there, just the final kick.\
Having the max sum avaiable, we only need to know if it's >= half of sum.
