Learned from this post
https://discuss.leetcode.com/topic/100240/java-o-n-3-dp-solution-with-explanation-and-simple-optimization

The question I first tackled via a traditional algorithm way, basically trying to find a definitive way to determine for any given string, what is the least times it needs to print.

I initially thought it should always paint the longest range in a recursive way. However the test cases revealed it is not the best solution. One example "cdcada", my algorithm would require 5 times and it's obvious it only needs 4 times.

So it comes back to this undeterministic problem that the solution can change if one extra character is added to/removed from the string. It's similar to the regex matching problem that would require dynamic programming.

In my understanding, dp is to cover all the possible cases by start from point 0 and use a few relatively simple rules to calculate rest of the array.

It is not hard to understand what the code is doing however it's sill a question of how the relatively simple rules are concluded and why they will give the optimal solution.

8/21/18\
Tried to do this problem again, after long thinking, I came to the same solution as the previous learned solution.\
I was trying to think of better dp algorithms however it seems O(N^3) is the best we can get.
