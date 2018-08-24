I am a little shameful that this problem took me quite some time.\
I know how to solve the problem soon after reading the question.\
The algorithm is to find the first digit from left that is smaller than the max number at right most index.\
The problem was how to implement it, changing a number into vector seems to be slow but realized there's no better way.\
Then I focused on how to find the first element to swap which can be done in many ways.\
And there was some back and forth when I realized my first solution has bug in it.\

Looking at discussion, there's a really great solution.\
One scan and keep the swap index candiates. Really beautiful.\
https://leetcode.com/problems/maximum-swap/discuss/107073/C++-one-pass-simple-and-fast-solution:-1-3ms-O(n)-time

8/23/18\
Tried second time, came up with a better solution.\
Still not as efficient as the above referred solution but is easy and short.
