It works when I used the same method as in the Word Search problem.

However the hint mentioned trie which I think makes sense.

So my implemenation of the trie solutions is to build trie from the matrix and then just match words in the trie.

It works fine, only thing is the trie building part is too slow because of need to exhaust all possibilities.

Then I looked at solution, the correct way is to build trie using the given words which is very fast, then go through the matrix to look in the trie.

It tooke me a while to write and some time to debug but was a good experience.
