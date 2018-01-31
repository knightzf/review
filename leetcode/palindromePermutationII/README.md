The hard part is to find the permutation when there's duplicates.

For a string such as "aabbcc" that has duplicates, first reaction is to sort it.

Normal permutation algo is a recursive call of swapping start element with every element and advance start index to call the function itself again.

But for duplicates, it's a little tricky because

1. You don't want to swap an element with duplicates of same element because the swap is same and will create duplicate results.

2. You don't want to swap an element with another element that has the same value as itself as it's essentially no change which will also create duplicates.

I did this by having two checks which isn't beautiful but did the job.
