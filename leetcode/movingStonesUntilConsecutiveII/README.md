The problem is difficult for a few reasons.\
I managed to come up with my solution after Hao's hint.\
1. Max is not that hard to think about, roughly all the empty slots.\
2. But is it really all the slots? what about for the special case there's only one stone on one side?\
3. It turns out no matter where there's special case, max move is the max of empty slots between stones[1]\
and stones[n - 1] or stones[0] and stones[n - 2]. For special case, only need to move one stone over from\
the other side.
4. Now how about minimum? Sliding window seems to be a good choice.\
5. Here's the catch again, for the special case, it's minimum 2 moves.

In the end, the code is not long but really hard to think of and fully understand.