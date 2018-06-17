I didn't find a good solution to this problem after long hard thought.\

Process:\
1. brute force, start from any idx and select subsquence of length 1, 2, 3, ... \
2. Think of a recursive solution, if begin and end chars are the same, we now have a smaller problem.\
   But otherwise I went into overthinking of trying to find a match of begin char from right or\
   match of end char from left or remove begin and end char.\
   By thinking of this, I know the complexity is big because how to search for match?\
   Scan is a bad idea, use a set maybe? Which isn't trivia either.\
3. I got stuck on this idea and even though there's hint of a dp solution, I was thinking of a dp\
   of different length, and for each length, you need to loop over shorter range results and then\
   again of finding a match that encloses the shorter range as close and possible.\
4. I finally went to see the discussion and it's so straight forward.\
   If start and end chars are different, the longest subsequence is either from start to end - 1 or\
   start + 1 to end.

I failed to find above relationship but went into overthinking the details which counters the purpose of recursion.\
It's a large blind spot in my mind which I need to take as a good lesson.
