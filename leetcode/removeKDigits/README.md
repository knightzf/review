It's kinda surprising to see the acceptance rate for this problem is so low.\
My idea is a greedy one, removing k digits means pick n - k digits.\
Each time find the min digit in the left most position.\
The problem is that it's not very efficient.

Looked at discussion, the good solution is still use a vector/stack to keep candidate digits.\
When new digit is lower than existing digit in the vector, try to replace to left most one in the vector.\
I also thought about this but didn't find this solution because it's a little bit tricky.
