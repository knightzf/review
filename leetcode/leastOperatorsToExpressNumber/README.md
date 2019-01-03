It took me quite some time to find this is really a x-nary number by having the expressions without parenthesis.\
At the beginning I thought I need to try out all possible expressions at possible length.\
With the realization, my solution is actually simple.\
Each number is can be constructed from x^n + a or x^(n + 1) - b.\
We only need to do a sort of binary search recursive call but the key is you don't want to get into infinite loop.\

It took me really long time to finally understand the learned solution.\
First step is to convert the target into x-nary format.\
Then for each digit in this x-nary number, it can be constructed by a * x^n or x^(n + 1) - (x - a) * x^n\
The result we want is sum of number of expressions used by each digit.\
But we can't simply sum it up because there can be overlappings between digits which changes the result total.\
So we do it accumulatively.\
We use 2 numbers: 
# number of operators from 0 to i when it forms the target we want
# number of operators from 0 to i when it forms the number that we can subtract from x^(i) to get the target

That was not clean in the explanation which took me very long time to finally understand.\
Also note:
# Each term has counted sign as an operator so we need to subtract 1 in the end
# To form number of second case using a previous result of second case will have overlap which we must account for
## e.g. when x is 10, (100 - 20) + (10 - 4), where first term contains -20 and second term contains 10