I thought for a long time, it's hard because it tries to find majority for any arbitrary range.\
There's no data structure that can do that, I thought for segment tree but felt it wasn't very suitable.\
Checked discussion and the idea is to randomly pick an index and check whether the number is the majority.\
If there's a majority, meaning the occurance is more than half of the time, to do the random selection 20 times\
which is very likely to bump into the number, very small change to miss it.