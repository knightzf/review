It's a relatively simple backtracking problem.
The only tricky part is how to keep track of used elements.
My solution is definitely not the optimal.

It seems the better idea is not to use stack but use recursion by marking already visited element to special character and call the function recursively for rest of the word.
