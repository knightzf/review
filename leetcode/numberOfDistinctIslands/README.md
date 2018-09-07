Can't pass one of the test cases on leetcode for some reason.\
It does return corrrectly in my local.

9/6/18\
Tried this problem again, without any thinking I did the union find algorithm by converting into a 1d array.\
One thing I failed to get is the 1d index should be equal to i * n + j, there's no m in the equation!
After finding the islands, need a way to know the shape, what I did was to convert back to 2d coordinate and put in a vector.\
Looked at discussion, they use dfs, basically from one point to find all neighboring points and in this process use a string\
to build the shape of island, for example "udlr", which is pretty smart.\
Now I think of it, it doesn't need to use union find although it works pretty well, dfs is the better choice here as the islands\
are connected.
