This seems to be a very easy question, first find all links, then dfs or union find.\
However both timed out.\
Also I noticed using gcd to find link between large number of inputs is already slow.\

The better solution is to find all primes and then find what numbers are divided by the primes.\
The question itself sets time limit too strict that even using the right algorithm will time out.

The key part is still union find.\
How to calculate the number of connected indices during union find was a hard problem that I failed to figure out.\
The learned solution is so brilliant that I had to think for a long time before finally understand.\

There's a few parts.\
* parent array, which is normal union find.
* count array, this keeps track of links an index has
* prime index map, prime number to index mapping. However the key is for each new number, we'll update the prime index map and count array for this index.
** Rolling is needed so that the count always adds to next seen index which requires the prime index map to always point to the last index that can be divided by the prime.

https://leetcode.com/problems/largest-component-size-by-common-factor/discuss/200546/Prime-Factorization-and-Union-Find