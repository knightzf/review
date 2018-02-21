I recently learned it's much better to use a temp value and only insert to result when index goes to end, \
instead of letting recursive functions to return vector of possible subresults.

The key here is how to avoid duplicates, the solution is not perfect, for example it will not work if the original word contains digits.
