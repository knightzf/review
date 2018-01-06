Idea is really simple, I looked at the discussion but it's not something extrodinary smart.

For each point, calculate the slope to all other points, the main thing is how to store the slope?

The solution is to use two parts and use greated common divisor to scale to the same amount.

I spent much time debugging on some crash because the less than operator wasn't written properly. Great lesson learned.

The details are a little tricky, need to consider the sign of two elements in the slope. Luckily the test case isn't too huge to debug.

Also need to consider same point case.
