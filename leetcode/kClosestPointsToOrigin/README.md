Spent so much time trying to use the implementation of std partition to do it.\
Always fails on edge cases.\
After some thinking, the problem is due to the std partition function only does\
swap one way which causes the edge cases of returning first or last iterator.\
The correct way to use it should be to partition twice, once with < operator\
and the other with <= operator, which will give us two iterators and this can\
cover the equal case.
