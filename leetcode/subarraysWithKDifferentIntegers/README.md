I was able to get ac on this problem but not very satifactory as the sliding windows\
isn't smart enough in the sense I can only partially use known data.

Found a brilliant solution in discussion
https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/234482/JavaC%2B%2BPython-Sliding-Window-with-Video

Instead of find the answer directly, it tries to find number of substrings that have\
at most K distinct characters.\
And the result is just a simple diff between at most K and at most K + 1.\
Nothing more can I say.