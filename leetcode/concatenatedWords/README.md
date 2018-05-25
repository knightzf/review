My solution is trie with dfs which is not too fast even with some optimization.\
For example, trie node contains a unordered_map instead of vector of size 26, which reduces memory usage when the input string is like aaaaaaaa.

Another way is to use dp, start from short to long words and for each word, only check if it can be formed by words shorter than itself.\
I also thought about it and thought it could be slow to look at all substrings but maybe it's not too bad.
