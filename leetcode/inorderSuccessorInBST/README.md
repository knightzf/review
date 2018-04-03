It seems you have to inorder traverse in order to find the next successor.

4/2\
Did this problem again, it appears you don't need to traverse the tree.\
If the target node has right children, then it's simple.\
Otherwise, find the path from root to node.\
Then check if each parent is a left child of its own parent.\
Very nice question and my solution beats 100%.
