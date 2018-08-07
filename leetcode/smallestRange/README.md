My solution is using a sliding windows, which essentially can be changed to merge K sorted array instead of using all numbers in the range.\
The solution from discussion is much smarter.\
The idea is the largest possible range is smallest start of range, and largest start of range.\
I haven't written the code myself, but I can see the idea.\
For disjoint ranges, it's simple.\
For overlapping ranges, the key here is to using a priority key of start and end values sorting by start value.\
Each time we take the top of queue, try to increase start by 1 and for overlapping ranges, it'll eventually come to second range.\
In this case, we gradually narrow the range until we moved off the current rage.\
At this point we know we can't go forward anymore as we need to include at least one number from the range.
https://leetcode.com/problems/smallest-range/discuss/104886/Clean-C++-priority_queue-solution-using-iterators
