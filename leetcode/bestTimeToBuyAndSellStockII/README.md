Although the problem itself is a simple one, basically find out the longest increasing subvectors and add the diffs.

However that's only true because of the restrictions and understanding of the problem.

I decided to go with dp, which suits the dynamics of the question itself.

There are two dp vectors, one denoting on day i and there is a open position, where the other means on day i no open position.

The values of two dp vectors depends on each other.
