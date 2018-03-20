This one is really hard to get right.

My thought start from left to right and it's obvious when counting of parenthesis becomes negative(assuming left is 1 and right is -1)\
we need to remove one right parenthesis, any one of it would work but should only pick first ) if there's a few consecutive ones

Then the problem becomes when there's more left parenthesis, it feels hard to select and remove n number of left parenthesis from a string

Looking at discussion, it says the other case is same if we look from righ to left. That's genius!

I tried to implement it which is tricky about indexes, you don't want to have duplicates but also don't want to lose valid results.

Took me a long time to finally figure it out, it turns out you need to remember last removal index.

3/19\
This is really hard to get right, the idea is not hard to understand tho.\
The second time I tried to solve this, knowning what the algo should be took more than a day.\
The key is to remember the last index we removed a character.\
My attemp was to always start from index 0 and only take the last right character for consecutive right characters.\
Hower it causes duplicates.

Example:\
()())r)\
We found invalid substring when we get to index 4.\
We can remove index 4 or index 1, resulting\
()()r)\
(())r)

When processing the resulting strings above, we find invalid at last index.\
They can both produce result below:\
(()r)

What a tricky one!
