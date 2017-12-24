My solution is a straightforward recursion with cache.

So it's basically a dp solution.

The more clever solution is to use a bottom-up dp.

For bottom row, the min value of each element is itself.

Then the row above, min value of each element is the less of its two children and itself.

In this case, we can reuse the same array to store the intemediate dp values.
