It feels like sliding window problem to me, but actually hard to write because we need to keep track of\
how many unique letters we have so far, and if there are 2, what are the counts for them.\
Besides we need to know whether it's possible to find a letter that's not in the range but same as the \
letter of majority.

After some thinking, I decided to start from each index and try to get as far as possible, if we see a diff,\
try to find if we can keep going after the diff. \
It is technically still sliding window but the normal template is hard to be applied.