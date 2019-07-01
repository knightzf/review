1. This is very similar to find the start of loop in a linked list.
2. Because there are n+1 element and values are only from [1, n], we can use the value as index to go through all elements in the array. 
3. Because there's duplicate, going through the array is like going through a linked list and there is going to be loop in the linked list.
4. Use array index slow and fast, with slow one step a time and fast two steps a time. When the meet (slow == fast), go to the next step.
5. Use two indexes begin and slow, they each walk one step a time, when the values they point to match, we now get the duplicate number.

6/19\
The problem is actually hard to fully understand.\
First need to understand the proof that two pointers will meet at the start of\
circle when they starts from beginning of list and meet point.\
The second point is to understand the start of circle is the duplicate number.
