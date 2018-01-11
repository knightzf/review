Unbounded knapSack problem.

My idea is similar to the bounded one, basically for the optimal set, it could contain some amount of object A.

So my solution is try out 0 A, 1 A, 2As and call the function recursively with rest of objects and rest of max weight.

It works, although probably not optimal.

The solution I see on geeksforgeeks is a dp one.

For a max weight from 1 to max weight, try out all objects + existing dp value for given total weight to find max. It is actually quite similar to my solution.
