I had the right idea but couldn't pass test as a O(N^2) solution.\
Then looked at discussion, it was so smart!!!\
For A[i], there are 2^i substrings where A[i] is the max,\
and there are 2^(n - i - 1) substrings where A[i] is the min.\
Thus for max we add A[i] * 2^i and for min we subtract A[i] * 2^(n - i - 1).
