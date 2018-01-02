The solution is very brilliant.

I've thought about it for a while, my idea is first group intervals into groups that are not separated without overlap, then apply some rules to count the number of elements needed in order to satisfy the intervals.
But I failed to actually find a good way to proceed.

Here is my understanding of the algo.

1. Sorting it very important, it sorts first by range end ascendingly and then range start descendingly.

2. Use two numbers p1 p2 to mark processed range.

3. A few possible cases

    a. range start <= p1, meaning we've already covered.

    b. range start > p2, meaning a separate range, we add count by 2 and set p2 to range end and p1 to p2 - 1

    c. range start <= p2, meaning an overlaping range, two possible cases

        (1) p1 + 1 == p2, we know start > p1 and start <= p2, means start == p2, we'll need to add count by 1
        (2) p1 + 1 < p2, then we were at case c before and we only added one element in previous case, now we need to add another one

       for both cases, p1 updated to p2 and p2 updated to range end

To be honest I still don't fully understand this solution but what I can get is the usage of p1 p2 lets us not to worry about which element to add to result set, because it can be different depends on the next range.
Instead it usese a p1 p2 range and check if this range can cover next range, if we really want to find out the result set, there needs to be more logic added to pick up the correct element.
