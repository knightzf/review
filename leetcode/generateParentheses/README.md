It took me quite a few days to think about this question.

My solution is simple, basically go through all combinations and check if it's valid.
Normally you loop n levels to find all combination but it's impossible to write for unknown n.
So the final solution is to prepopulate the string and flip certain bits of it by looking at the binary format of the index.
For example, the string starts as ((((((, when index is 3, flip two bits to ).
It's not very efficient as it creates a lot of invalid strings.

The learned solution is a recursive way. It's easy to follow.
The problem is I still don't know how to prove it creates all valid combinations.

4/19\
My sol 2 is easy to understand as it is a recursion of sub problems.\
The backtracking one is much better in efficiency but it's a bit hard to come up with.\
The idea with backtracking is nothing but a dfs but there needs to be tricks to\
make sure there is no invalid result. 
https://leetcode.com/problems/generate-parentheses/discuss/10096/4-7-lines-Python
