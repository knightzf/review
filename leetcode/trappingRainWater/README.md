My initial idea was to calculate water by each level, although I haven't written the code, I think it's going to work, but low efficency.

After talking to Sheng, he mentioned the algo and I implemented it.

The idea is to find ranges [i, j] by looping the array so that height[i] <= height[j] given all elements between i and j are less than the smaller of height[i] and height[j].

Then the problem becomes subproblems and each section is easy to calculate the value because we only need to calculate the total and minus all the blocks that took up space in between.

If the numbers in the array are descending, the loop above won't be able to capture such ranges. That's why we need to loop again from end to start with same logic with the exception that now we want height[i] to be strictly smaller than height[j].

Why? Because we don't want to calcualte same area twice is the numbers in the range are for example [2, 0, 2].

These kind of problems are really logical reasoning and I am not very good at them.

4/19
My sol 2 uses 3 scans to get max left and mex right for each index and finally \
compute how much water each position can contain.\
There is a even better solution by moving from both sides to middle, essentially\
two pointer solution where it keep comparing left and right max and we know for\
each position how much water it can contain. Similar idea but more brilliant!
https://leetcode.com/problems/trapping-rain-water/discuss/17391/Share-my-short-solution.
