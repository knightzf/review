My solution is a dummy recursion way which tries to find left and right subtree from the root, but need to check if the right subtree values are all larger than root, which is not very efficient.

Looked at discussion and there is a much better solution.

The idea is to use a stack and push values visited, if we see a value larger than the current stack top, it means we are in a right subtree, keep poping stack until we are out of the left subtree.

The only check is to keep a current lower bound and if any unvisited value is less than this bound, we know it's not good.
