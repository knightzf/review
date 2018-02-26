This problem is good in two ways.

1. Let me review the best way to determine if a tree is bst.\
   By calling a recursive function with left and right range so that each node is visited only once.

2. For this problem specifically, need to return size of tree.\
   Also need to reset the range when it fails for certain node because itself could be a valid BST root.
