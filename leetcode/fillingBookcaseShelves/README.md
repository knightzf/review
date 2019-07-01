I was only able to find the dfs solution, which of source times out given large input data size.\
The learned solution isn't very different from my dp definition, but the complexity was much less.\
What I couldn't get was the dp conversion relation.\
In my thinking, dp by index is too simple that it lacks whether the next book can be put on the same level.\
However the learned solution solved the problem by looking back instead of looking forward.\
In the end, it solves the problem by filling last level by 1,2.. books and the we already know the rest.