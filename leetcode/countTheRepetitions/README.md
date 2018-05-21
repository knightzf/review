Thought process:\
1. Brute force, but given the problem it could be 10^8 characters long.\
2. We want to find how many S2 can be found in S1, have to somehow use information of s2 and s1.\
3. What if we find how many s2 can be found in S1 and then we'll know number of S2.\
4. The key difficulty is s2 may start at different positions in s1.\
5. What about we find the end index and end s1 count of s2 starting at each possible position?\
6. That is basically my solution.

My solution is definitely not fast enough, but it's max 10^6 instead of 8.\
Looked at discussion, they all use the same idea, but they find when it starts to repeat.\
i.e. if we start from index 0 on s1, at which point we'll start from index 0 again.

This will greatly simplify the solution, I didn't actually do it but should be doable with running some test cases.

It feels great to be able to find right idea and solve the problem by myself.
