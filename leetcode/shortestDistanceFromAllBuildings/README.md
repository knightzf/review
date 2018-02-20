It's a typical BFS problem when you can go from any empty point and find the toal min distance to all buildings.

However the learned solution has a few genius points.\
1. It updates grid after each bfs from a building, so that subsequent walks should only walk to positions of last bfs.\
2. How to keep track of total distance? It uses a global matrix which is updated when walked to this position.\
3. How to keep track of distance to the building of each bfs? Use a local matrix and count the distance.\
4. How to find the total minimum distance? Use a global variable that compares against each point of the total distance matrix.

It is really difficult to come up with such a clean and neat solution although it looks harmless.
