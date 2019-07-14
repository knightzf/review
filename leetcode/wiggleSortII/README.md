This question is really hard, spent almost a day trying to understand it.

The basic idea is to find the median and put numbers smaller than median in even indexes and larger than median in odd indexes.

If there's no duplicates, it'll just work.

What about when there's multiple numbers equal to median? Where to put them?

The consluion is to place smaller numbers from right to left on even indexes and larger number from left to right.

In this case, numbers that are equal to median will be separated as much as possible.\
But that's a hunch, how to prove?

With some drawings, it's easy to find when there's floor(n/2) median numbers, the above algo will work.\
How about when number of medians is larger than floor(n/2)?

0. when there are more median numbers, in order to fail, this number must appear in both smaller and larger halves.
1. if n is even, having more than n/2 median will not work because no matter how hard you try, there will be at least two median numbers next to each other.\
2. if n is odd, the only time it'll work is n/2 + 1 medians, for example 7 numbers with 4 medians, they will have to be places on even indexes.\
   In order to satisfy the requirements, all rest numbers will have to be larger than median which contradicts with the problem that median number exists in both smaller and larger halves.

How to prove it must be allocated in this way that one is smaller than median and one is larger than median?\
It doesn't have to. For example 9 10 7 8 5 6 3 4 2 1\
However using the median way is also going to work for above case, but there's no proof that median way is guranteed to find a solution if there's at least one solution.

The next thing is how to put the numbers in to their positions in place?\
After finding nth element, the numbers will be soreted as [larger section] [median section] [smaller section]\
It uses an index mapping to find the final index.\
For example:\
original idx: 0 1 2 3 4 5\
final idx:    1 3 5 0 2 4

The formula to get final index is (1 + 2*i)/(n|1)\
The n|1 is to find next odd number if it's even and itself when it's odd\
When need an odd number? Otherwise the mapped index will be same for the second half.

And the final replacement algo.\
Use 3 indexes, left, i and right.\
For each i, find its mapped index and check the if the number is equal to, larger, less than median.\
If larger, swap with mapped index of left and increase i and left.\
If less, swap with mapped index of right and decrease right.\
If equal, increase i.

7/19\
The learned solution is easier to understand than the virtual index solution.\
The key is to put big numbers on odd indices from left.\
And put small numbers on even indices from right.\
So that numbers equal median will be put to two sides of the array.
