First try is simply BFS but timed out for large number.

Learned sol is also my thought, basically use the summation formula to find a number that's >= target.

The the problem is the diff between number - target

If the diff is even, meaning we only need to flip one number in 1 .... n to achieve the target

Otherwise when diff is odd, here is the little tricky

If n + 1 is odd, we add n + 1, then the diff is now even and we are back to previous situation.

If n + 1 is even, we add n + 1 and n + 2, then the diff is now even and we are again back to previous situation.

It's an easy problem but actually quite tricky to come to the solution.
