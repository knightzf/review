This is a great question.

I've seen such problem many times and couldn't always figure out the best solution.

My initial thought was naive, basically keep track of coordinates that belong to an island using an list of island sets, \
and seprate memory for keep track of possible neighbors for each island.\
For reach new island, go over the list of islands by checking their neighbor sets and merge when necessary.

It'll work but I know it's not the best solution.

Thought for a while and I fell asleep. Looked at discussion and it's greate.

Learned a few things:\
1. Use a direction vector to find 4 way connection points.\
2. Flat 2d array into 1d array and only store their parent idx.\
3. For points in one island, they can have different parents but they should all trace back to same origin.\
4. When merging islands, need to update the parent idx, basically go up a level in the tree, otherwise it will not form the structured mentioned in 3.
