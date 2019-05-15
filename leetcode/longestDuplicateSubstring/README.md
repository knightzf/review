The problem is simple and I got to the right(trick) idea to use binary search.\
The next problem is how to search if there exists a substring of certain length that has duplicate.\
Normal search is O(N) which times out.

There are way solutions in discussion:\
1. Binary search + Rabin Karp algo for string search. Rabin Karp is a hashing algo that calculates new hash\
value by computing one extra character, which is O(1) in comparision.
2. Suffix array. This is the correct approach, idea is really simple but hard part is how to optimize it. I spent\
almost 2 days to finally get some idea of it.

https://leetcode.com/problems/longest-duplicate-substring/discuss/290852/Suffix-array-clear-solution