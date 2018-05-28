Thought process:\
1. Request 1: Need to be able to locate k/2 th element quickly.\
2. Request 2: Need to be able to remove an element and add an element.\
3. From past experience, can use two priority queue to find median.\
4. However the remove of element is not trivial.\
5. Then I thought, perhaps we don't actually try to remove from the queue, instead record it.\
6. Then for any read operation, we'll check if the element has been removed to find a valid element.

Looked at discussion, there's no more efficient solution.\
My code looks a little complex but it beats most submits.
