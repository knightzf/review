At first I started from begin to end, the problem first is when to exit? Because there will always be x or y that stays small.

Tried many time and finally got it all working, then got timeout.

Then I tried to start from end to begin, which seems much faster but still time out.\
Because from (1, 2) to (999999, 2), it takes too long to do individual additions.

Finally found the solution to first reduce the end x y to similar range by division and then reduce x and y each time.
