It took me quite a few days to think about this question.

My solution is simple, basically go through all combinations and check if it's valid.
Normally you loop n levels to find all combination but it's impossible to write for unknown n.
So the final solution is to prepopulate the string and flip certain bits of it by looking at the binary format of the index.
For example, the string starts as ((((((, when index is 3, flip two bits to ).
It's not very efficient as it creates a lot of invalid strings.

The learned solution is a recursive way. It's easy to follow.
The problem is I still don't know how to prove it creates all valid combinations.
