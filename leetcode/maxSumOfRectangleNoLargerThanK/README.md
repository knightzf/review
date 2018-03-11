This is a good question that I learned something.

Most obvious solution is n^4.

This solution, essentially computes all possibilities, however is much faster.

The logic to tranpose the matrix is only useful when m is greatly larger than n.

Basically it computes accumultive sum of each row start from col 0, 1 and etc.

So everytime we get a vector of size m(row count.)

In order to find max range sum that's <= k, use an set to store accumulative sum, and for each sum,\
find if there's existing sum so that their diff is <=k.

I thought about the 2d binary index tree algo, which is fast in terms of calculating rectangle area,\
but in order to find all possible ares sizes, it still needs n^4 time.
