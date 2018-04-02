Learned from here http://zxi.mytechroad.com/blog/tree/leetcode-218-the-skyline-problem/

This is called the sweep line algorithm

The idea is for each range, make it two events, enter and leave.

For entering, compare the height to current max and if it's greater, set this as a new upward critical point and push the height.

For leaving, remove the current height, then compare if the removed height is greater than remaining max, if it is, meaning we have a downward critical point.

The special case is if there are multiple events for a given point, we need to handle entering first and we need to handle event with larger height first and leaving event smaller first otherwise we'll create incorrect critical points.

The special case is handled by the sorting.

The actual code is pretty short but the idea is really hard.

The other way, instead of using a multiset, we can use a heap to store the heights, it needs to support add, remove and update which requires a hand written heap class.

4/1\
Did this problem again, by myself, now I can say I have a better understanding of this type of problem.
