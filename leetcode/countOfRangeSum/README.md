I spent a lot of time on this question, still can't say I fully understood it.

My solution is naive, basically put the sums into a map and for each sum, find the complement sum and find the max index that has the sum.

The learned solution is much different.\
The idea is similiar to the Count of Smaller Numbers After Self.

Basically here we are trying to find out number of sums after each so that the diff between them is in a range.\
It is done using a similar merge sort with counting method.

The count however is different from normal merge.\
For each index in the left part, find the range in the right part and add the size of range to result.

7/19\
Had the correct thinking of using binary tree, but was thinking too aggressive\
causing wrong answer.

1/5/2021\
The merge sort solution is great, make it nlogn instead of n^2.\
The reason it calls the function with (0, n + 1) is the same as calling the function with (1, n + 1) plus the code below
```c++
int t = 0;
for(int i = 1; i < n + 1; ++i) {
    if(sum[i] >= lower && sum[i] <= upper) ++t;
}
return mergeSort(1, n + 1) + t;
```
