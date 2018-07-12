This is a good question.\
Original thoughts was to compare substring from s2 to s1 sorted which is correct but slow.\
After some thinking, it feels a lot like sliding window solution.\
In which I used unordered_map and try to loop through s2 as much as possible until hits a char not in s1.\
Also try to slide as much as it needs so that no char count is < 0.

Looked at solutions provided by leetcode, the best solution is also a slide window which uses a count to see how many of 26 char counts of two strings match.\
And shift the window to adjust the count, when count == 26 means we find it.\
It's smarter but harder to get it right.\
Other solutions were really not so good and I am surprised they actually work. Probably due to the limit size of 26.
