I used the normal solution which is n^2.

There's a better sol in discussion https://discuss.leetcode.com/topic/28738/java-python-binary-search-o-nlogn-time-with-explanation

The idea is based on the observation that the smallest tail number for length 1,2,...n subsequences are increasing

For example, say we have nums = [4,5,6,3], then all the available increasing subsequences are:

len = 1   :      [4], [5], [6], [3]   => tails[0] = 3\
len = 2   :      [4, 5], [5, 6]       => tails[1] = 5\
len = 3   :      [4, 5, 6]            => tails[2] = 6\

Since tail array is increasing, we can do binary search in it.

Ecah time, do one of two things

1) If num is larger than all elements, append to tail and increase size by 1\
2) Else replace one of the elements in tail array via binary search

The final size of the tail array is the maximum subsequence length

This is very brilliant and very hard for me to understand.

Tried to watch videos on youtube but only one person talked about it and he couldn't explain it very well.
