I spent a lot of time on this question, probably over 40 minutes.\
Before I only thought about cases where one rectangle has one of the vertices inside another rectangle.\
Then test cases reminds me of other possible cases which seems to be more and more corner cases.\
At this point I think my previous thought was wrong.\
Then I realized in order for two rectangle to overlap, their x range and y range must overlap.\
Now the problem is much simpler, reduced to a one dimensional problem.\
Only trick is the test case has int overflow case, which I really dislike.
