This one is really hard to get right.

My thought start from left to right and it's obvious when counting of parenthesis becomes negative(assuming left is 1 and right is -1)\
we need to remove one right parenthesis, any one of it would work but should only pick first ) if there's a few consecutive ones

Then the problem becomes when there's more left parenthesis, it feels hard to select and remove n number of left parenthesis from a string

Looking at discussion, it says the other case is same if we look from righ to left. That's genius!

I tried to implement it which is tricky about indexes, you don't want to have duplicates but also don't want to lose valid results.

Took me a long time to finally figure it out, it turns out you need to remember last removal index.
