Spent almost an hour on this.

At the beginning I thought this is just a one iteration cherry picking problem.

Then I realized it needs initial value and need to make sure each step health is > 0;

So it becomes an reverse dp problem.

dp[i][j] means the health it needs at (i, j)

The health need to combine with the current value and still be positive and it has minimum of 1.

The first point at bottom right has dp value of 1 because we are trying to find the minimum health at start.
