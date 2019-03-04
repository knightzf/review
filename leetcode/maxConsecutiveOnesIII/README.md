My solution works but is a little messy.\
The problem I was having is to have K = 0 case, how to denote dp value if K = 0?\
Also how to move forward from existing values?

Learned solution is much cleaner, it allows startIdx to be larger than endIdx and uses a \
tricky so that the result is always >= 0.
https://leetcode.com/problems/max-consecutive-ones-iii/discuss/247543/O(n)-Java-Solution-using-sliding-window