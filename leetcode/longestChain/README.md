Question:

Given a vector of words, find the max of remove chains so that at each step a letter is removed from a word to form another word in the list.

Solution:

Sort input words by length.

Start from shorted and set their chain len to be 1.

For longer words, try removing one char from all possible indexes and see if the result is in the list.

Using a map/hashtable to maintain word -> chain len.
