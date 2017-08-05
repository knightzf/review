1. For a linked list with loop, it must be in the shape: staight line + loop in the end.
2. Use two pointers, slow (one step a time), fast(two steps a time). They must meet somewhere in the loop.
3. Because they meet in the loop, they must always meet in the same point of the loop. The reason is fast is twice the speed as slow, fast must walk two circles before it meets with slow again.
4. Let's say it takes slow k steps to meet fast after they start from beginning.
5. That means distance of fast - distance of slow equals size of loop.
        2k - k = r -> k = r
    5.1 There is a huge assumption that the meet happens during the first loop of slow
    5.2 The reason is even if fast and slow starts from start of loop at the same time, their next meet will be at the same spot after one loop by slow. Otherwise fast is already ahead, thus they will meet before slow goes the full loop. 
6. Suppose there are s steps from beginning to start of loop, m steps from start of loop to the point they meet. It means:
    k = s + m
7. From 5 and 6
    r = s + m -> r - m = s
8. So we can use two pointers, one from beginning and one from point they meet, each one step a time, when they meet, the point is where the loop starts.
