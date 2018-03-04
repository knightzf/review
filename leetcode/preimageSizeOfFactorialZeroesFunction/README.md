Key obervation here:\
1. Number of 0s changes every 5 number.\
2. Number of 0s can be found by dividing number by 5, 25, 125...etc.

The algo is a binary search, for target number of 0s, find the actualy number that produces so many 0s in its factorial.

One thing to notice is not all numbers exist, e.g. there can't be 5 zeroes.

So the cloest number we can find that produces less than or equal to 5 zeroes is 24, which has 4 zeroes.
