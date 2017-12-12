It took me some time to figure out because I tried to optimize backtracking.

I didn't remember the normal backtracking method.

It should normally be

Create a stack, for each level, keep pushing different states and use a validator to check if the state is what we want.

My solution here is correct however hard to get right at first try.

Also it's a little bit tricky to write the function to determine if two numbers are diff by only one bit.
