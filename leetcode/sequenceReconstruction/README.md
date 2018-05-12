My solution is normal toplogical sort, easy to understand but not the most efficient.

In discussion there's a much clever solution.
https://leetcode.com/problems/sequence-reconstruction/discuss/92574/Very-short-solution-with-explanation/137236?page=1

The idea is to find the constraint that any two consequent elements in orig should also be consequent elements in one of the seqs.\
Why is that?\
1. If they are in same seq, then they have to be next to each other and same order.\
2. If they are in diff seqs, then there's no seq to determine the relative order of these elements, thus can't find unique solution.

That's already brilliant, then how to implement the idea?\
1. store the index of each element from orig.\
2. for each seq, check neighboring two elements and make sure \
    a. each element can be found in the orig\
    b. relative index satisfies and store the pair into a set\
3. loop through orig, and check if each pair can be fount in the set

I can only say practice has a limitation, which is it doesn't increase my IQ.\
Frustration is norm.
