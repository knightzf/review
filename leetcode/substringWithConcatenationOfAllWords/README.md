My initial thought: dfs, which times out badly.\
There were a few things that were hard to think of\
1. The substring can start from any index, which seems to suggest we should try all the possible start index.\
2. How to mark each word as used and how to know we've used all the words?\
3. How to avoid copying the same data structure that contains the usages of words for each try?

Haoting reminded me of the template for sliding window solution and I tried it out.\
We only need to run the sliding window from index 0 to len - 1, where len is each word's size.\
And the rest is the details in making sure the indices are correct.