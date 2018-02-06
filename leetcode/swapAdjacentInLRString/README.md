It's one of those problems where you need to see through to the core.

My idea is simple, given two rules, try all possible changes and see if it will match.

In order to save scanning the string two many times, I tried to use a vector of pair to denote possible places of swap.

However it's more complicated because need to condsider what changed after one swap, could create multiple new possible swaps.

At this point I found I am very likely in the wrong path which may work however extremely difficult to implement all the details correctly.

The learned solution is very smart.

After studying the rules, we found L and R can never change their order in the string, thus we first remove all X and see if the two remaining strings match.

Then we use to pointers to scan the two strings, igore all X and each time they stop the letter they point to should match.

We also know L can only move to the left and R only to the right, checking the relative value if two points we can know if it's possible to match.

For example, we now come to L and i is 4 and j is 6.

Because L can only move to the left and no matter how we swap start string, the L at index 4 can never be moved to index 6.

This is real mind gym we should talk about, no fancy math, only about logic reasoning.
