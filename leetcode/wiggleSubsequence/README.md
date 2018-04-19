This is very similar to the longest increasing subsequence question howerver I failed to find a solution.\
The idea is almost the same, difference is here we either update the last element or append new element.

Why this work?\
This is a greedy based algorithm, which is usually hard to prove.\
The key here is we assume the result always starts from nums[0], here's how to prove.
* if nums[0] is smaller than nums[1] and there's an optimal solution from index i.
** if nums[i] is smaller than next element, the nums[0] must be smaller than nums[i] otherwise we have a better result
** if nums[i] is larger than next element, then nums[0] must be larger than nums[i] otherwise we have a better result
** for above two case, we can always replace nums[i] with nums[0] so our proof is complete

One thing to notice is that same with longest increasing problem, we only get the max length, the result vector isn't necessarily the subarray we want.
