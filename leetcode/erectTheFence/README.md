I took some time to think about it and my idea was right,\
start from left bottom point, and find next point by checking the slope of rest of points.\

After talking to Haoting, I realized it's the convex hull problem.\
And there was a similar problem in leetcode before but I forgot about it.\
The above solution is called Jarvis march which is O(N^2).\
There's a better nlogn solution called Graham scan.

Idea is we sort the points by slope and distance to the starting point.\
Notice distance compare is opposite when slope is positive vs negative.\
And the idea is we always check 3 points and make sure they are clock wise, other wise pop until they are.\
It was difficult to make it correct at first try, I spent about 2 hours to finally pass the tests.
