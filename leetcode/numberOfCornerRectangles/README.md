Idea is simple, from each point, look at possible corner point that can form a rectangle but it exceeded the time limit.

Improved solution is first go through the grid and record all the y indices on each x.

Then go through the smaller map, and do basically the same thing, only look up in the original grid when necessary.

Looked at the solutions of other people, ideas are different.

They having a loop of two cols (col1 and col2) and one row.

For the loop of row from 0 to n, count the number of rows where grid[col1][row] and grid[col2][row] are both 1

If the count is no less than 2, it means there are rectangles, depends on how many rows, the number of rectangles are

count * (count - 1) / 2
