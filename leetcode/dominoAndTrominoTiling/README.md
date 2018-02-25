I knew it's a recursion/dp problem when looked at it, however it didn't appear to be very straightforward to me.

Just as I was about to give up, I tried to write down a few scenarios and it becomes much cleaner.

So I wrote the code, worked for small numbers, than it failed tests of larger numbers.\
So I changed int to long, it failed again for even larger numbers.\
I stumbled for a while and realized the numbers are so large that even long can't hold them.\
I tried double, which produced slightly difference results.\
Then I looked at other people's submissions, realized I just need to mod it at all calculations.
