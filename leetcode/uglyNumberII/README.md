I had similar thoughts but failed to produce a valid algo.

The idea is this number must be 2^x * 3^y * 5^z

So each smallest new number must be a result of some existing number times 2, 3 or 5

I tried to nail down limited number sets that will produce everything or start from the first number that can produce a value larger than current max by timing 2, 3 or 5 to current max to find next min new number but it's very inefficient.

The learned sol sets the indices from 0 and each time a new number if produced by looking at multiplication minimums, advance the index by 1.

In this case, it's impossible to create any gaps in the new numbers.
