My solution is to first determine largest possible plus sign size and for all possible locations check if it's valid.

It works but times out badly for large data set. Tried to optimize lookup, didn't work.

The learned solution is to find up down left right neighbor counts for each point and then go through to find the max.

It uses extra space to store important information to speed up the process which is much better than my brute force.
