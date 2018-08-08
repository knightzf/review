I thought of a recursive solution, which takes total number and total number in range.\
It's correct but slow.\
After checking the solution, I realized I almost got the dp relationship.\
Basically I couldn't see after placing the first element from 2 to n, the subproblem is dp[n - 1] + dp[n - 2].\
dp[n - 2] is obvious, but dp[n - 1] is less.\
It's because for example we place 2 at first index, the rest numbers are 1 3 4\
We can treate 1 as 2 to get dp[n - 1].
