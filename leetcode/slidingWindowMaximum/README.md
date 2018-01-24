My solution keeps a set of k numbers and replace one number at each windows move.

The learned solution is very smart, it usese a deque to store the indices.

Each time, it removes the indices out of range from front.

Also it removes indices with corrspondings values less than the new value from back.

So the queue is sorted by index increasingly from front to back and sorted by value descreasing from front to back.
