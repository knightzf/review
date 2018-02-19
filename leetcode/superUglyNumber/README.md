It is obvious that next number is a multiplication of an existing number and one of the prime numbers.

My thought was to keep a list of possbie values (i.e. after finding the next value, remove from list of possibles and multiply this value with all prime numbers as possible next values)\
It works fine however the growth of possbiel values is quick which uses a lot of memory and time.

The learned solution is based on the same idea, but instead of keeping tracking of possible values, \
it keeps track of possible values that when multiply with respective prime number, could be the next value.

In this case, we only need to keep track of k possible values (where k is number of primes), this reduces both\
time and memory usage.
