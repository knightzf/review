I didn't find the right direction and had to check the answers.

What the problem is trying to do, is to allocate the new stations to the existing gaps so that the max distance between any two stations is minimized.

It feels really complicated because there's no definitive algo to allocate the K stations.

And I couldn't think of good dp algo either.

The answer is simple, basically do a binary search and try out the min max distance in the gaps and count number of new stations to compare with K.

With binary search, the min max distance have to converge and we exit after satisfying precision requirement.
