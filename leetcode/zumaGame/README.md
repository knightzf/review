I spent almost two days with the problem.

Thought process:\
1. Brute force bfs solution, kinda hard to write, althought not impossible.\
2. Can surely use dfs instead of bfs.\
3. Tried to implement the solution using dfs.\
4. At first it could pass some tests but fail badly at others.\
5. Realized I haven't tried all possible locations, changed the code.\
6. Again failing for some other tests, this time I had assumption the order ot insertion didn't matter.\
7. The assumption was wrong, order does matter.\
8. So I had to try all possibilities using permutation algorithm (by swapping.)\
9. Then it fails timing out.\
10. Had no proof, I added the check that I will open put new balls to a position that has neighboring balls with same color.\
11. This passed test however in discussion there's an example that will fail the above assumption.\
12. So it means we still want to check all possible positions, which has to be slow.

Lesson learned:\
1. dfs can be used as another way to solve bfs problem, with lower efficiency.\
2. assumptions are bad, can't make assumptions just because you think it is.
