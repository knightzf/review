Was thinking of a recursion solution, basically take one char out and then let the rest run, but it seems to be very inefficient.

Then I realized, as long as the number of rest chars is greater than number of most frequent char - 1, it definitely has an answer.

I spent some time debugging how to construct the final result and it doesn't look very beautiful but it works.
