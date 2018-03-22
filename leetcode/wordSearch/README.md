It's a relatively simple backtracking problem.
The only tricky part is how to keep track of used elements.
My solution is definitely not the optimal.

It seems the better idea is not to use stack but use recursion by marking already visited element to special character and call the function recursively for rest of the word.

3/21\
I spent quite some time on this problem but somehow couldn't pass the last test case.\
Finally I figured out it's because of word to search is lower case.\
My solution isn't optimal as I used more extra data structures where we can just use the same input matrix and update its elements for dfs.
