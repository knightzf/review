My solution is obviously in a wrong and diffcult path. Basially first locate the node that is less or equal to target value by inorder traversal.

Then traverse the tree by layer and find the target node in this structure.

Then there are 4 situations, node in the left tree and it's a left child or right child, also node in the right tree and it's a left or right child.

For the situations, there are different ways to handle which is complicated to write.

However it easily timesout for large unbalanced trees and very hard to get the 4 situations right.

The learned solution is just great, speachless.

It's a recusion method which delegate the split into subtrees by checking the value with target.

For the returned pair, it updates the current node's left or right child and replace one of them values in the pair.

It looks very simple in the writing but that's really deep understanding of tree strucutre.
