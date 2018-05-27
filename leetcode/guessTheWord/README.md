My idea is correct, basically make a guess which reduces number of possible candidates.\
However because of the search space is 6^26 which is very large.\
Always guess from begin didn't pass.\
Then I tried to switch between begin and end which got accepted but i felt that's just luck.

Looked at discussion, same idea, but the solution choose a way to improve the strip down process.\
Basically for each word, it finds diff with all other words.\
We choose the word that have minimum 0 matches, that means even if we get 0 from master, we'll be able to strip out most possible words.
