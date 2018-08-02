I spent time on 3 nights on this problem and unfortunately had to read the answer.

The problem is hard in a few ways.\
1. First reaction, dfs, which is clearly impossible given the number of inputs.\
2. Then perhaps DP? Couldn't see a good dp conversion.\
3. Checked hint and saw it'a greedy problem, which is in general hard.\
4. I tried to change the end time to latest start time for each course, due to my instict.\
5. It wasn't too wrong but hit a major issue sorting the input.\
6. In general it's easy to say we should try to put courses with earlier end date first but there's also course time.\
7. Tried to sort two ways but it's still awkward, it's just hard to see which way to sort can give a clear path.\
8. Tried a few greedy solutions, all failed by different cases.\
9. When looked at the solution, the key idea is we shoud squeze short and earlier close date courses together.\
10. The other key idea is when we see a new course that can't fit, only if there's an existing course with longer duration should be replaced.\
11. Unlike other problem we should pop the queue until fit.\
12. The reason is we gained nothing by poping out more than one courses to fix a longer course.\
13. We want most number of courses, not the longest time.\
14. Learned something new from this problem!
