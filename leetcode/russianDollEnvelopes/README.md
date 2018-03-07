My solution times out. It's because there's no definitive way to know which is the next one to pick from all the possible ones because there are two factors to consider.\
In the end my solution is probablly N^2 complexity.

The learned solution is just brilliant. \
First it sorts the inputs so that for the same width, it sorts height descently.\
This ensures for each, we only need to check the ascending heights after itself.

This makes it the same as finding the longest increasing subsequence problem which is Leetcode 300.\
It's based on the fact the minimum element of all length n subsequences increase as n increases.

For an existing subsequence array, look at the coming element and try to insert into proper place by binary search.\
If it's larger than the last element, append to the end.

This dynamic algorightm avoids looking for subsequence for each element, instead it will give you the longest subsequence after one loop.\
This is truely brilliant and I am glad I had the chance to review it again!
