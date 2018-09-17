It really took me a while to sort out the solution.\
The idea is simple, try to find out number of subarrays where A[i] is the mininum.\
It requires to find out how far to th left and right that A[i] remains smallest.\
I figured out by using two dp vectors from two directions.\
The other key point is for duplicate numbers, we don't want to count the same subarray twice for duplicate numbers.\
So the left or right vector should stop at duplicate numbers.