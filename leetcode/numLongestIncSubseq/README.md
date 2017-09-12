The key idea is how to find the longest increasing subsequence.

The linear search from beginning works, but requires each time to look up all previous substrings and decide what to do with new value.

The learned solution is a recursion method, idea is.

Let P(i) be the number of max length substrings that end with nums[i].

So P(i) is equal to max of P(j) + 1 where j < i and nums[j] < nums[i].

The rest is just details, a bit tricky but not too much.
