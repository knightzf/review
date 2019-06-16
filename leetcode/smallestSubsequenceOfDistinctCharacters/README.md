My solution is using a sliding window and keep track of furthest index where there are enough chars left to\
satisfy the requirement. Which works but it's O(NlogN).

Learned solution is similar in terms of it also uses a counting logic but it's a greedy solution by choosing\
the smallest possible letter at each position and make sure the replaced chars can be found later.\
Very brilliant!