3/24\
Thought about this for long time when I worked on this the second time.\
Why?\
It's not easy to easily check if max of left sub tree is smaller than current node and min of right sub tree is larger than current code.\
My first try uses helper funtion to get min and max which involves a lot of repeated calculation.\
My second try this time breaks the question into 2 steps: first to check each node with its two children, then check each node with substree min/max given the first check is good.\
It is a lot of improvement, however there's even better solution, which is in order sort. Because a bst will render numbers in order we only need to keep track of previous node in a inorder traversal. Brilliant!
