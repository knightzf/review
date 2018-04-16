Spent a lot of time on this question.

First thought, because it's almost impossible to know which index you should swap because swap has consequence on other positions.\
So simple idea is for each position, try either no swap or swap and call next step recursively.\
It works but as you can probably tell, it times out as size of array grows.

I had a hunch there is a dp solution. But my thoughts got stuck on how to find a greedy algo to determine which index to swap.\
Finally I gave that up and tried to look for dp relation and it's quite similar to the buy sell stock question.

I feel ashamed that same question, with some modifications, got me again.\
I am still far from really understanding those algorithms.
