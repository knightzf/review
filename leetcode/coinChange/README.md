This is a good question.

First I tried to use the naive backtracking which times out easily when target number is large.

There are two ways to solve the problem:\
1. Backtracking with pruning. \
   The minimum number of coins must be distributed to several different coins.\
   Keep a global minimum count.\
   Start from largest number and divide target by this number and see if remaining number can be solved by remaining coins.\
   If not, try reduce the number of this largest coin and try again.\
   Tricky part is, you need to compare temporary counts with global minimum and discard those that are large.

2. DP.\
   The idea is to create a dp array to find all minimum counts for all amounts. Bottom up approach.\
   It works but is significantly slower than first method.
