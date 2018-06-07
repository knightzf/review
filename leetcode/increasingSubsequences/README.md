I spent a lot of time trying to find a solution without using a set to store the possible results.\
The final code isn't too pretty but performance looks ok.

Looked at discussion, there's a better solution using dfs.\
It constructs a temporary vector by pushing and poping elements, very smart.
https://leetcode.com/problems/increasing-subsequences/discuss/97124/C++-dfs-solution-using-unordered_set
