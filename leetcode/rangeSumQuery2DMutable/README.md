My timed out solution uses a vector of segment trees which timesout.

From this problem I've learned another data strucutre, binary indexed tree or fenwick tree.

https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/

The property of the bit tree is sum of tree[i] and value of all its parent nodes.

The way to find parent is to remove last set bit of i.

The way to construct the tree is to update values for itself and all chilrens until it reached end.

How to remove the last set bit of i ?\
i -= i & (-i)

It involves binary reprentation of a number. \
Two's complement is to flip all the bits and add 1.\
which is equivalent to find first 1 from right to left and flip all rest bits.\
Then i & (-i) is to keep the last set bit of the number and all other bits to 0.

The opposite operation is similar\
i += i & (-i)

The property of bit tree is all numbers are sum of powers of 2, which makes lookup and update both logN operations.

The learned solution is a 2d bit tree which contains bit values both horizontally and vertically.

The sum is found by\
sum(row2+1, col2+1) + sum(row1, col1) - sum(row1, col2+1) - sum(row2+1, col1);

The upper left corner has been deleted twice thus need to be added.

I spent almost a whole day on this question, but it is very valuable experience.
