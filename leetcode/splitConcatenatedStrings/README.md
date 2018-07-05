I am glad I figured out this problem by myself.

1. We know the final result must be from a max char in some string.\
2. First tried to find a greedy solution but whether to reverse a string can depends on other strings.\
3. So we need to try both possibilities, original and reverse.\
4. This leads to time out which is no surprise.\
5. Try to think of a better solution, is there a way to divide into subproblems? Unlikely.\
6. Thought for a while but couldn't get it.\
7. Then I realized other than the string to start, all other strings must be in the largest state.\
8. So we make sure every string is in largest state and combine them into a big string.\
9. Then for each string contains the max char, we try from all locations, with original order and flipped order.\
10. This successfully converted an exponential problem into a polynomial problem.
