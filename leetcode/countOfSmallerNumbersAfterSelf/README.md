My solution, very simple, use a multiset to hold all numbers and for each number count from begin to lowerbound,\
then remove one element equal to current value. However it times out.

There are two solutions from the discussion.\
1. Number of smaller elements to its right means the flips from its right to left during a stable sort.\
   Store original number and original index, then do a merge sort.\
   At each merge, count the number of flips by checking diff of index after merger vs original index.

2. Use a special tree. Goes from right to left, insert each element into the tree, keep track of number of elements smaller than current node's value.
   It is very smart idea that only updates the result vector when the insertion finds the final position.
