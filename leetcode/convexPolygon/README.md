I knew it's a math problem.\
Thought process:\
1. Check the p1, p2, p3 slopes and determine if p2 is in the correct position.\
2. Found slope isn't a good indicator.\
3. Next step is to find the y = ax + b formula and compute the mid point, compare with p2.\
4. It seems to work but fails for some cases.\
5. Then I realized I should start from lower left most point and the sequence could be clock or counter clock wise.\
6. We only need to make sure the above validation always returns same result for each point.\
7. We should skip 3 points with same x value or y value because we can't return true or false as sequence matters.
8. Then I had two special cases when p1 and p3 are on same x value and y value.

Looked at discussion, there's a formula to find if 3 points are convex.\
Which is to calculate a determinant and make sure they are in the same sign or 0.

I haven't looked into details but I think it's a generalization of my solution.\
I'm happy to have finally solved the problem anyway.
