Was thinking of someting like keep track of all the section it has walked and for every new walk check if it will cross any of previous path.\
Like the sweep line algorithm which should work but will be complicated.

After discussion with Sheng, we only need to check the values of last few steps in order to know.

Why?\
1. There are two cases it will not cross itself.\
    Expanding or Contracting but with steps smaller then i - 2 steps\
2. If it's contracting it's very easy to check.\
3. The most tricky step if when it first contracts.\
    Need to check if it ends on the same x/y axis as i - 3, or\
    for the next step, can it actually walk the full length of its i -2 step (see below)?

________
|       |
|       |
|
|             |
|_____________|
