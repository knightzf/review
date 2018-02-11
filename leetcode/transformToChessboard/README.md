It seems to be a normal backtracking problem, but because of the special requirements, it's much faster to pruning.

Given the requirement of being a chessboard, the number of 0 and 1 on each row and col are either n / 2 or n /2 + 1.

Also because the movement won't change the elements on the row or column (only order is modified),\
it implied the rows and columns can be the same as first row/col or the oppsite of it, and number of equal/opposite row/col are n/2 or n/2 + 1.

If there are row/col of other patterns, no matter how you move, it can never become a chessboard.\
(don't have a proof but it feels that way after written down a few examples)

So the idea is now simple, first count patterns of firs row and col and validate.

Then count the number or row/col that are same/opposite with first row/col and validate counts.

Also count the misplaced row/col numbers, misplaces means from first row/col's perspective, the same/opp should be in the even/odd positions.

After knowing number of misplaced row/cols, the number of swaps is simple, note one swap changes two misplaced row/col.
