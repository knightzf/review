I thought for a long time and it's like one old chinese saying "while boar trying to eat a hedgehog."\
Learned a great solution from discussion
https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/discuss/92242/ConciseEasy-to-understand-Java-5ms-solution-with-Explaination/136978?page=1

Idea is the lexicographical order looks like a tree.\
However we don't want to in order traverse the tree.\
Everytime from current node we try to get to the right neighbor.\
If the steps is less then k, we move to right neighbor and reduce k.\
Otherwise we can only go one step, which is its first child.

Next problem, how to calculate steps between two numbers x and x + 1?\
By adding diff between x and x + 1, 10x and 10x + 10, 100x and 100x + 100... etc\
Also need to exit when the numbers we compare is larger than max number.
