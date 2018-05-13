My solution is naiive, which is N^4.\
In discussion there's a better solution
* flat 2d matrix into 1d by convering (i, j) into unique number, store those with value 1
* for all combinations of A and B value 1 indices, diff their index and count for the diff
* because it's essentially shifting of 2 1d arrays, the max of diff count is the result we look for
