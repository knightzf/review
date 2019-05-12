Similar to Permutaions, the only difference is there could be duplicate elements in the array.

To solve this issue, we basically need to sort the array and skip elements that are the same as previous one.

One issue is that after each swap, the rest of the array might not be sorted correctly, so there needs to be sort at each recursion, thus copy of vector at each recursion.

It's not terribly efficient but you need to keep track of availble elements one way or another.

4/19\
No real simple way to handle the duplicate issue.
