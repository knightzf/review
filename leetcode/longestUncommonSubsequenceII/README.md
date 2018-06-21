This is another problem that I am very happy with because not only did I figure out the solution, but also I improved my solution.

1. From Question I, I first thought it's just the longest unique string is the most uncommon substring however it's proven wrong.\
2. Then I think if that's wrong, the only thing I can do is to store the substrings of visited strings and for a new string\
   I'll just search to see if there's match in these substrings, if not obviously it's the answer.\
3. However it's not very efficient as finding all substrings is 2^n operation.\
4. Thinking how I could improve it.\
5. Then I realized I only need to search if the current string is some other string's substring for which I can just use to indices to scan two strings.\
6. Viola! That's our solution indeed.

This is also one of the problems that you have to change how you see this problem, it's enormously difficult if you go with description way.\
However once you realize the real problem behind the complex description, it becomes much cleaner, like hot knife in butter.
