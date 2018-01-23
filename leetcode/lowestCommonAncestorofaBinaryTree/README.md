My solution is very slow because it traverses the tree many times.

Looked at discussion and it turns out it's a classic problem.

The idea is to recursively call itself with left and right child.

For the function, if node is null or if node is q or q, we return.

Why? Because p and q are either on two separate subtrees or p and q are parent-child relationship.

In this case, based on the return of call to left and right child,

if they both valid, means p and q are on different subtrees and we return root.

if left is null, means both are on the right.

if right is null, means both are on the left.

