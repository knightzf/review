The problem is from geeksforgeeks, for some reason the code couldn't compile or run on their website.

I took some test case from the comments section and it seems results are correct.

The idea is loop through the packs, try itself, and try itself with previous max values (add or replace) to see if a local max can be found.

Now I think about it, it might not be 100% correct because I only try to replace one element, in reality it may be better to replace multiple elements with this element.


I looked at the explanation. It is a really good solution.

The key is for any element, it's either in the optimal set or not in the set.

So the formula is the max of

maxValue(maxW - weight[n], value[1...n-1]) + value[n]

    and

maxValue(maxW, value[1...n])


Because it's solving same problems in the recursion algo, it's natual to convert it to dp or use a cache, which is trivial.
