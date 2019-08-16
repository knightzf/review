The problem is really hard in how to determing the draw result.\
Draw is not a simple repeat of existing state, rather it's the optimal both parties can do.\
I tried DFS solution for a few nights but went nowhere.\
The learned solution is a toplogical sort type where it starts from known states.\
The key is still how to determine draw?\
It's those nodes cannot connect to a deterministic color.
https://leetcode.com/articles/cat-and-mouse-game/

8/16\
This time the learned solution has an unproved assumption that if the total\
number of steps are 2 * n and we still don't know a deterministic result, it\
is going to be a draw.

It's somewhat intuitive to see, even if it's not 2 * n, it must be a finite\
number.

With the assumption, the code is actually simple dfs, the trick of the result\
is for all possible next steps, if current player can win, then
we know there's deterministic result. Otherwise if not all the possible results\
are for the opponent to win, then it's a draw.
