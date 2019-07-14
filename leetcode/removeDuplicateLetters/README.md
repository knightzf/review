My solution, which is different from discussion and not very fast, however works correctly.

The idea is greedy, basically try to find the smallest char in all possible choices and see if there's enough left for rest of chars.

7/19\
My sol2 is same idea, basically try to find smallest possible char by checking\
the count map. However the solution in discussion simply constructs a new\
string and calls the same function while my solution goes back using the same\
count map. \
However my solution is much slower.
