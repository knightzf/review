I spent much time on this problem and finally was able to pull it off.\
There are smarter solutions in the discussion but the key idea is same.

I started off with a slightly wrong idea by a few observations:\
1. If the bit is 1, we can put a 0 here and find solution of any number of length <= length of digits on the right.\
2. If the bit is 0, we can leave it and find solution to the number formed by remaining digits on the right.

I made a mistake thinking it's easy to calculate the first case, which is simply doing a loop,\
that assumes consecutive 1's length and let remaining bits 2^n possibilities.\
This is wrong because I need to gurantee the remaining bits don't have consecutive bits which is almost same as the problem itself.\

I then figured for both cases, it should be a recursive call to the function itself.\
Now the problem becomes how to find solution of length n without considering what number it is.\
I then figured it's same as if we provide number 11111 as input.\
This is because for given digits, any number > 1100000... is not going to be valid.\
So the key here is if we have 2 consecutive 1's, we should stop after this bit.\
And if we see a 0, we don't need to go any future because we have covered all possible cases by checking the number remains on the right.

This is the type of problem that you think you can figure out with some efforts but ended up spending lots of efforts.\
But it is indeed a very good problem.
