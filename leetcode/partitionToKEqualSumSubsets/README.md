I thought about this problem for very long time and in the end figured it out.

First impression is DFS, however I knew DFS could have some problem, even with given max count of 16.\
However I couldn't find other better solution, so I implemented anyways and times out as expected.

I also thought there might be better/greedy solution but got stuck in the idea of DFS.\
It's very hard to change your idea once you started.

Then I realized the fact if we start from the largest number, and if there are two possible cases\
that will sum up to target average, for example 2 or 1,1. We should prefer using single number as\
1,1 can also be put in the same bucket if we need or be more useful when they are in diff buckets.\

But we can't say the same thing if we start from the smallest number.\
So my solution is to always try to find largest numbers to get target number.\
It also fails quickly, once we can't satisfy one number, we know there's no solution.