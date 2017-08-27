I spent quite some time on this question. Not because it's particularly hard or anything. Rather it's becuase it feels awkward of what is a clean and effcient solution.

The input array is nothing more than a tree represented in an array but in order to find sum of all root to leaf pathes, we need to know which ones are the leaves and how to quicky find the path. You can always loop in the original array but it feels very inefficient.

Then it's quite obvious we either create a real tree or still use array but fill all the holes instead.

My choice is to use array and fill all the holes, it's straightforward to do the conversion.

Then the question becomes, how to calculate the sum? You can't apply the normal divide and conqur way for a tree because the nodes are added multiple times if there's multiple paths.

We could always go through the array as a tree and find out who are the leaves and jump back to root to sum them up. Then I thought, why not mark each node in the array during conversion so that it's obvious to see who is the leaf?

It becomes easy at this point to implement. But it's still a N + NlogN algorithm and I don't see a better solution.
