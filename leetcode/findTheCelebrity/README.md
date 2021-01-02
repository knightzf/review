My solution is very naive, n^2 solution.

Looked at discussion, there's better one.

First go through the list, pick candidate from 0, if candidate knows i, set i to be the candidate.

After the loop, there must be a candidate.

Now we only need to verify if eveyone knows the candidate and the candiate knows nobody.

3/24\
Tried second time, didn't find the optimal solution.

1/1/2021\
Use two indices to find a possible candidate, then validate the candidate.
