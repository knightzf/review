My idea is to find the height first, then gradually count the number on the lowest level, however it times out for large input because it's still using q to count.


The learned sol is much better because

1. 1 + 2 + 4 + ... + 2^(n - 1) = 2^n - 1

2. For a node, measure the depth from left and right, if they match, means it's complete, otherwise recusion to perform same thing for the left and right child.

6/19\
I got it wrong, thought i need to count all complete nodes and it turns out if\
I just simple recursively visit all nodes, the run time is almost the same as \
the smart solution which is to check the depth of left and right.
