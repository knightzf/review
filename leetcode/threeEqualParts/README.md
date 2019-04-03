The problem is actually easier than it looks.\
My thought process:\
1. Since we want to split to 3 parts, let's first try subproblem of split to 2 parts.\
2. Then natually we can try all possible split, but too slow.\
3. Now I basically got stuck until I see the hint of a binary search.\
4. I then thought of binary search for split into 2 parts.\
5. My main focus was still how to know do the next step if current split failed.\
6. It turns out the key is we only need to consider number of 1's.\
7. With equal number of 1's, if we can't find 3 subarrays matching, then there's no such result.\
8. It can be done in O(N) instead of logN.
https://leetcode.com/problems/three-equal-parts/discuss/183922/C%2B%2B-O(n)-time-O(1)-space-12-ms-with-explanation-and-comments