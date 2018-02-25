I spent a lot of time on this question, still can't say I fully understood it.

My solution is naive, basically put the sums into a map and for each sum, find the complement sum and find the max index that has the sum.

The learned solution is much different.\
The idea is similiar to the Count of Smaller Numbers After Self.

Basically here we are trying to find out number of sums after each so that the diff between them is in a range.\
It is done using a similar merge sort with counting method.

The count however is different from normal merge.\
For each index in the left part, find the range in the right part and add the size of range to result.
