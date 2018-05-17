Great question!\
It looks and feels very similar to other types of questions, however it's a little different.\
I spent some time and finally figured out the solution.\
The difficulty is the numbers we look for are 1 3 2 type.\
It's not hard to observer that if we find maximum of 3rd number, any number on the left and is smaller than this number means we've found an answer.\
However it's hard to put this in an O(N) solution.\
The solution is to use a stack and we use it to find the max 3rd number.

It's easier to do with an example.\
1,3,-1,8,-7,-3,6

We scan from right, when we reach 8, we know the max 3rd number is 6 and then any number on the left less than 6 is good.\
How to do it?\
Use push numbers to the stack if less than stack top element, otherwise pop stack and the popped number is a candiate of 3rd number.\
We can find the max 3rd number.
