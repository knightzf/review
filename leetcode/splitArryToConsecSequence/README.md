This is something I don't fully understand or have a solid proof this is the correct solution but apparently it works.

The idea is actualy simple, instead of keeping a list of sequences while looping through the array, it keeps a list of sequence length for each node.

Always try to append the current node to shortest subsequence by looking at the previous node.

Why this works? The gut feeling is that where there are duplicate numbers in the array, appending to shortest subsequence is always better than appending to a longer subsequence because otherwise it's likely to create longer subsequence and leave shorter ones incomplete.
