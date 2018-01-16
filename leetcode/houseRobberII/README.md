This issue is similar with one difference that we need to know if value we calculated includes nums[0].

My solution is to use two dp arrays, one definitely includes nums[0] and the other doesn't.

In the end because of the last element of first dp needs to subtract nums[0], that makes it less obvious which is the max dp value we can get.

Instead I tracked max values of two pb array and then compare two maxes.


Looked at solution, basically same idea, just a lot cleaner.

The idea for any two consecutive houses, one has to be not robbed, which breaks the chain. Meaning for example house 0 and house n - 1, at least one of them must remain unrobbed.

So he calculates max from house 0 to house n - 1 and the other from house 1 to house n. Then compare the two maxes.
