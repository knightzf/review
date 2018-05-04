It took me one hour to finally start to understand the learned solution.

At first, I misunderstood the question and thought it only allows changing one specific letter to another specific letter.

Then looked at discussion, found it's not the case.\
My naive solution will be start from any index and go forward to make at most k replacements and check the length.\
The sliding window solution is much better.\
The idea is given a substring, we know which char appears the most times.\
The rest chars are assumed to be changed to this character.\
However if the number of changes is more than k, what do we do?\
Move start index to the right until the requirement is satisfied.

Actually when I took a close look, it seems the max occurance count may also change due to the start idx change.
The code doesn't take this into account.

Another solution properly addressed this issue.
https://leetcode.com/problems/longest-repeating-character-replacement/discuss/91285/Sliding-window-similar-to-finding-longest-substring-with-k-distinct-characters
