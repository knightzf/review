I came up with two solutions but failed because of timeout.

The idea is similar, checking min steps for each index and until we get to the last index.

The learned solution is better as it sees the steps as level of trees.

For example, the array {2, 3, 1, 1, 4}

0 step can get you index 0
1 step can get to index 1 and index 2
2 steps can get to index 4 and index 3

So the algo is a O(N) loop and once we can reach the end at step k, that's the answer we are looking for.
