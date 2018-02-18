This is a great discussion\
https://leetcode.com/problems/minimum-height-trees/discuss/76055/Share-some-thoughts

My thoughts were simple, just start from each node and find max path length, in the end we'll know the answer.

The learned solution is much brighter, it's similar to the topolocial sort where it starts from leaves and one step at a time until they merge.

One thing to note is that there could be at most two nodes, because if there's more say 3 nodes, one node out of 3 will become the new root.
