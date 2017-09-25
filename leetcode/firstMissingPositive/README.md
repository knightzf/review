It really takes a genius to see through this problem.

Because we are looking for fist missing positive number, for a size n array, unless it contains numbers from 1 to n, the first missing positive number must be between 1 to n.

So the learned algo is to go throught all numbers, put all numbers between 1 to n to its position (1 at iddex 0).

Then go through the modified array and check first element that its value != idx + 1

There is a little trick: look at one index and if the number doesn't fit the above requirement, put it to its designated position by swapping it with the element at designated position.

So a loop is required and should avoid infinite loop by checking a few conditions.
