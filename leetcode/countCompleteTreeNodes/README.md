My idea is to find the height first, then gradually count the number on the lowest level, however it times out for large input because it's still using q to count.


The learned sol is much better because

1. 1 + 2 + 4 + ... + 2^(n - 1) = 2^n - 1

2. For a node, measure the depth from left and right, if they match, means it's complete, otherwise recusion to perform same thing for the left and right child.
