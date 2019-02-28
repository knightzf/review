Initial thought is to do dfs from each node, but given the large input, it will be slow.\
Then the point becomes how to avoid traverse the same path multiple times.\
Essentially for any dfs that fails, we need to keep all the previous visites nodes bad.\
Otherwise we'll need to mark the node as good.

I use value >= 2 as bad and 0/-1 as good.\
In discussion they use 2 as bad and 1 as safe, which seems cleaner.