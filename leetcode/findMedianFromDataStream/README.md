My solution is simple, use a map and keep track of the iterator to the middle item. It's a little tricky in the implementation details but nothing too difficult.

There's another solution from dicussion area where it's using to heaps (max heap and min heap) to store the largets and smallest half of the number.

Using two heaps we can have access to two middle numbers.

3/9/19\
Hao asked me about this problem, I thought it was some kind of dynamic sampling problem but realized you have to store the numbers.\
I looked at the solution in discussion, which is using two priory queues, which is brilliant itself\
However I then thought more about, it can be solved by using a multiset, the only trick is to handle the case of adding a number equal\
to the number the iterator points to, and it did work! Congrats to myself!
