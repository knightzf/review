The problem is simple, given all possible combinations, find a string that covers all the combinations.

The intuition is if when they link together, each string can use the n - 1 chars of previous string.

Assume it exists such string, the solution is a dfs approach.

Start the string with '0000', try to use last 3 chars '000' and try next char so it becomes '0000x'.

Then for '000x' to see if next one can be found and etc.

So the solution is not too complicated.
