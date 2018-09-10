It was a contest question, I couldn't find an efficient solution in time but I was on the right track.\
The key idea is don't think about real numbers, only think about relative relationship.\
For example, 0, 1, 2, 3 and 3, 5, 6, 9 is no different.\
The other key idea is to constraint possible number of choices.\
For example, if first char is D, the possible choice for first char doesn't contain 0 (or the smallest number.)\
Also because of current choice of number, it impacts the range of choice of next number.\
This part is where it becomes a little tricky but in the end it's the details that can be figured out.

Looked at discussion, the idea is similar, but it's direct dp instead of recursive call.
https://leetcode.com/problems/valid-permutations-for-di-sequence/discuss/168278/C++JavaPython-DP-Solution-O(N2)