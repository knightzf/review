The problem is how to find next permutation?

There is an algorithm and the coding is actually just translation of the algo.

But if you don't know this algo, it's quite hard to think of a solution by yourself.

Credit to  https://discuss.leetcode.com/topic/15216/a-simple-algorithm-from-wikipedia-with-c-implementation-can-be-used-in-permutations-and-permutations-ii

1. Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, the permutation is sorted in descending order, just reverse it to ascending order and we are done. For example, the next permutation of [3, 2, 1] is [1, 2, 3].

2. Find the largest index l greater than k such that nums[k] < nums[l].

3. Swap the value of nums[k] with that of nums[l].

4. Reverse the sequence from nums[k + 1] up to and including the final element nums[nums.size() - 1].
