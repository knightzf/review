Two solutions

The slower but simpler solution is basically a DFS, uses a stack and push in all valid possibilities. One bug is how to loop from a given point in matrix.

The faster but more complex solution is a back tracking without the need of stack and copy of data.

Instead it uses a more complex data strucutre to keep the list of possible solutions for each point and an index to which the possible valueis placed in the matrix.

Also for backtracking, it loops back to first possible point and reset all points along the path.
