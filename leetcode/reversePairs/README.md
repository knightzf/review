Spent a few nights and one afternoon to study this problem.

My thought process:\
1. brute force, O(N^2)\
2. Start from right to left, use an array to keep visited numbers sorted, then for each new element, do binary search.\
3. Issue with this approach is, inserting into an array is not O(1), it's O(N) worst case.
4. So above solution is O(N^2) worst case.
5. Looked at discussion, mentioned merge sort, which proves to be a viable solution, also easy to understand.
6. Then I spent a lot of time trying to understand the binary index tree solution.

Review of BIT\
1. The idea is based on the fact each number is sum of powers of 2.\
2. Each element in the tree is sum of some elements.\
3. The number of elements of the sum is always power of 2.\
4. The number of elements is the last bit 1 and the rest of 0s.\
5. For example, idx 8 is sum of nums[1] to nums[8].\
   idx 7 is sum of nums[7]\
   idx 6 is sum of nums[5] and nums[6]\
6. Because it's traditionally used to find sum of range, for insertion, it inserts into idx + (idx & (-idx))\
7. For look up, it sums values of idx - (idx & (-idx))\
8. We notice the insertion stops when idx is larger than the range and for look up, it stops at idx that is power of 2.\
9. Because of this property, we can construct and look up sum of ranges.\

For this problem\
1. BIT here is used differently.\
2. Each element means some number of original objects that are >= object corrsponds to this element.\
3. For insertion, it adds elements in this tree with smaller indices idx - (idx & (-idx))\
4. And for look up, it sums up elements in this tree with larger indices idx + (idx & (-idx))\
5. We use a copy of original array and sort it.\
6. For each number in the original array, we try to find index of (2*num + 1) in the sorted array.\
7. Then we look up the index in bit tree to find how many elements have indices >= this index.\
8. Then we insert idx of num into bit tree for future lookups.

BIT tree is pretty hard to truly understand and I can't say I now know it well.\
Let alone in this problem it's using BIT tree in a much different way which adds the complexity.\
I think I need to watch some of the MIT algorithm courses to better improve my algorithm knowledge.
