Two solutions.

First solution is from discussion where it tries to find next candidate character by looking at remaining counts of characters and use another vector to keep track of next valid positions for each character.

Second solution is from discussion with Sheng. The idea is similar to what I thought about but didn't come to a solution.\
The idea is to construct sub arrays by putting the most frequent characters to beginning of each sub array.\
Then layout rest characters by each column.\
Finally check if there any subarray (except last one) with size smaller than k or total len of subarrays is larger than orginal string size.

It may be intuitive, but how to prove it works?\
The key is if each sub array (except last one) is at least length of k, then we can be sure each character is separated at least k.\
For those of smaller frequency, they can fill at most (n - 1) subarrays and they can never such situation that one element on two rows are separated less than k.

The second solution, which seems rather complicated, performance is a lot better because there's much fewer lookups.

Sheng is really smart and feel sorry to see him leave.\
However it's good for him and wish him the best.
