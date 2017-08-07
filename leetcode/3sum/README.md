1. For my slower solution, the idea is straightforward, find sums of all pairs, then loop through each element to find match. Used extra maps and set to make sure the result doesn't contain duplicates.

2. For the learned solution, the idea is also not very complicated. First sort the vector, for each possible first element, scan the rest of the vector using two indices from two sides. There are some checks for boundary conditions so it's a bit tricky to get it right. 
