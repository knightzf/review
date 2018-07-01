I thought for a long time but couldn't get a good solution.\
The only thing I could think of is to find sums from 0 to i, then for every index check if there's existing sums that satisfies.\
The difficulty is we need to find the shortest subarray, and we can only sort by sum which requires checking all possibilities.

The learned solution is very smart, similar to other problems I've seen before.\
The key here is to keep track of increasing sum indices.\
For a new index, pop from back to get rid of all sums that are larger than this index.\
Why this works? Because we want to keep indices of lowest sums possible in the queue.\
Since the shortest subarray we want must start from smallest possible sum.\
For example if we have index in the q that has sum of 100, now the new index has sum of 50, \
for upcoming indices that will be one of the answers, it will match 50 more likely than 100.
