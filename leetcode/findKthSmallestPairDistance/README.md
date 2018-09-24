OK so this is a little tricky.

First, we sort the array, and find the min and max diff, all good.

Then we do a binary search by taking the min and max diff, caculate mid.
Count the number of pair diffs that are smaller than mid, if the number is smaller than k, meaning mid is too small.
Otherwise mid is too large. So and and so forth.

The trick here is mid is very likely not one the pair diff numbers, yes we can do binary search but how to get the actual diff number that is kth smallest?

Let's put an example.

We want to find 2nd smallest diff in the numbers below which is 3 (6 - 3)

1 3 6

If mid is 2, number of diffs smaller than 2 is also 1.

So the logic is while low < high, only increase low by 1 or set high to mid.

In the end, the low should merge into the target number.

For the logic to count numbers less than target, loop through numbers and find diffs. The key is not to reset j to i, but leave it here.

That's because when you find the first j that nums[j] - nums[i] > k, increase i by 1, now nums[j] - nums[i] is likely to be no bigger than k so we don't need to reset j.

9/24/18\
Tried this for the second time, this time used binary search and had some extra logic to account for the case where there's multiple pairs with same distance.\
However the efficiency is not as good as the seeming scan solution.\
This is because scan is essentially O(N), mine is logN.\
Anyways I am happy to find the solution myself this time.
