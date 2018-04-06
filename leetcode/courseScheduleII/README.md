This problem is a classic algo question, called toplogical sort, which I haven't fully figured out.

Hower the solution that I learned is pretty easy to understand.

The main difference is it creates a hashmap of course -> dependent course instead of the other way around.

Also it uses an array to keep track of each course's number of dependencies.

Then it uese a queue to keep track of course without dependencies.

Every time for an course in the queue, reduce the dependency count for the dependent course and push back any course with an updated count of 0.

If we exit the queue loop without populating result vector to size of total course count, it means there are circular dependencies.

4/5\
I did the problem again knowing the solution. Tried very hard to write concise code but failed.\
However my solution is fine, the previous learned solution is also very nice, using a queue instead of dfs.\
I should have remembered recursion can always be written iteratively.
