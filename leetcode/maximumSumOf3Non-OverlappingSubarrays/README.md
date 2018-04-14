This is a great dp problem.\
Question is simple, find 3 indexes that the sum of subarrays is max.

Brute force is easy but not optimal.\
I felt there was a dp solution but couldn't figure it out.\

The learned solution is great in terms of it convers this problem into 3 sub problems.
* Find minimum index from left that produces max sum for left subarray as of index i.
* Find minumum index from right that produces max sum for right subarray as of index i.
* Try all possition middle subarrays together with information we gathered above to find the global max.

The tricks are:
* Index operation is complex until you have a very clear understanding
* Finding left indexes are easy to think from a dp's view
* Finding right indexes is a bit unconventional as we start from right to left
