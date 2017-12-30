Very simple problem, the only tricky is how to minimize the number of iterations.

Basically the idea is if you start from index i and stopped at index j, then you can skip indices from i to j because they will also stop at index j if not earlier.

If index j is before i, it means there is no solution.
