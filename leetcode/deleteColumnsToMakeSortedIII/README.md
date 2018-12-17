Glad I figured out the problem by myself, even though it may not be the optimal solution.\
First reaction is dfs, which surly works but times out with larger input.

After long thought, I've come up with a dp solution that dp[i] means longest substring ends at index i.\
Then for each new index, I check all previous dp values to see if the new element can be appened to the substring.\
Need to make sure all strings satisfies the requirement or we skip.

Looked at discussion, seems to be the same idea. Happy!