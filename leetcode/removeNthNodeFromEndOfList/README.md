It's really easy to iterate through the linked list and find the target node.

However it can be done more efficiently by having two pointers with faster n steps ahead of slow and then iterate the list to find target node.

4/19\
My solution uses a queue of size n + 1.\
There's a better solution from discussion where it uese two pointers,\
that are n nodes aparts, keep moving until the second pointer reaches end.\
The it's very easy to remove.\
But there's a catch that it requires an extra node before head,\
otherwise need to handle empty list cases.
