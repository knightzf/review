I spent a few nights and finally found a solution myself.\
The problem has two parts:\
1. find stamp index for each char in target string.\
2. construct sequence of placing stamps so that it matches 1.

My solution was essentially bfs at step 1, then for step 2, I found it hard as each stamping can propagate\
to other stampings. At last I found I only need to consider the relative order of two sequent stampings,\
which is why I used topological sort, which itself caused me some time to write the code.

The learned solution, uses dfs at step 1, and he clearly defines the rules which is a huge step forward than me.\
For step 2, he ingeniously found the relative relationship of up and down sequences is that we only need to \
reconstruct the odering by placing down sequence reversely and up sequence orderly. This is far too brilliant!
https://www.jianshu.com/p/cb4cbd11511b