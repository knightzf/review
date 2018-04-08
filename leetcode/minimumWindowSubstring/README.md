In order to find minimum substring that contains all letters of target string, all I could think of is to find all substrings of size 1, 2, 3... and whenever the first substring covers all letters of target, we are done.

However it's very fra from O(n) complexicity.

I had to check the solutions in discussion, found something really genius.

https://discuss.leetcode.com/topic/30941/here-is-a-10-line-template-that-can-solve-most-substring-problems/12

Idea is use a map to store occurances of letters in target, then go throug the other string by subtracting counts from map.

When we find the first match, start to move start index from left.

The very tricky part is here, how do you know if moving start index looks at letters in the target or not?

It turns out because we only subtract when looking for match, when there's match, letters not in target we've gone through have negative values.

So if we move the start index and after addition its value is positive we know we've now see a letter in target.

In this case, the end idx will need to move further to the right in order to find next match.

It can be generalized for all such substring problems. Very smart and it's like backtracking.

I tried to think of a dp solution but doesn't seem to fit into the dp model.

4/8\
Did the problem again, managed to work but code looks ugly.\
This is a very good summaration of the general substring problem.\
https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
