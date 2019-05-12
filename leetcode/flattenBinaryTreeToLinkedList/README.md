The key is to understand the problem, it is to convert tree into linked list in place, which means all nodes only have right.

It's not to create a new linked list.

5/19\
Preorder traversal, the tricky is the prev node is already changes, so need\
to save down left and right children before going to recursion call.
