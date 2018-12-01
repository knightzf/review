I spent too much time on this problem.\
Given the order matters, I first tried direct DFS, which obviously times out when input number > 10.\
Then I thought there might be a deterministic way to move the stones.\
Tried to move stone based on number of connecting neighbors, the code is quite ugly and hard to write.\
Besides it fails when there's a connectiong stone between two islands.\
Then I thought, oh maybe we only need to find number of islands and we can move all but last stone.\
This problem is actually pretty simple but my logical thinking wasn't good enough.

There's a learned solution which is way smarter.\
The idea is axis is the only thing, which then can use union-find.\
It also set y to be negative numbers so that it becomes a 1d problem.\
In the end, use total stone number - island number is the result.
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/197668/Count-the-Number-of-Islands