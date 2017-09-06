It's actually not very difficult, but a rather unique way of thinking.

I got stuck to the idea of finding a counting method by only looking at key elements of the array because obviously we can't calculate everyting in the array.

The leanred solution is a binary search by setting low of 1 and high of m*n + 1 at beginning. Keep searching until high and low merge.

The key is given a number, how to calculate the index of the number in the matrix.

The answer is take a loop of rows, add up count of numbers in each row that are smaller than the number.
