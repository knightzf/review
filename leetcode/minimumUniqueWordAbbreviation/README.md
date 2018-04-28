The problem is really hard, even brute force isnt' so easy to write.\
The difficulty lies in one word can be abbreviated in many ways, make the search costly.\
Normal thinking will lead to find all possible combinations which is definitely not the best option.

First observation, two words need to match in size to have any conflict.\

The genious solution is to use a bitset, for any word in dictionary, the letters that match target are\
of little interest because no matter these letters will always match one of the abbreviations.

We can find all possible bitset for size n and to match all words, if any matches, it's not a solution.

The optimization is to preprocess all words and OR them, only these with value 1 we need to care about.

The rest is bit operations that is complex and error prone.

It's a good problem in that it refreshes my mind with one more possible way to think of such matching problem.
