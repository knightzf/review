Idea is simple, hard to get all the details correct.

6/19\
My original solution times out as it's O(N^2).\
Learned solution is so great, in that it uses kmp in this problem by adding\
reversed string to the end.\
In this case, the longest common prefix for the last char is our answer.\
Only special case is to when lcp is 0, which is the worst case where we can\
take the reverse of s.substr(1) and add to the front.
