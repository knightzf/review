I am very happy with this problem because I gradually came to the optimal solution.

1. Looks like a dfs sort of problem, had my first version, which is correct however times out quickly.\
2. Then I rethink about it, found for each coin, we can calculate all possible numbers it can get to with existing values.\
3. There was some little tricky part but finally I got it work however it's about 6% percent.\
4. The reason it was slow is because it need to create a new map each time and then copy back to the original map.\
5. Also it has 3 levels of loop which is obviously slow.\
6. Then I tried to think if there's ways to optimize it by updating the map directly.\
7. Found it's hard because map insertion changes the iterator.\
8. Then think perhaps I can use a vector.\
9. First version got results really large because my loop strucutre still the same but updating on the same vector causes some duplicates.\
10. Then I realized I don't need the last loop because x + n * y can always be found by x + (n - 1) * y plus y.\
11. Then it becomes a final 1d dp solution.

Looked at discussion and realized this is a knapsack problem which is np complete meaning it doesn't have an easy solution.
