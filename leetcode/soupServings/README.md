This problem is tricky in that N can be very large.\
I first tried to find the probability by taking 4 cases starting from N and realized the possible cases are growing exponentially.\
Couldn't think of a smart solution, I gave up on it.

Looking at discussion, people noticed that as N gets to the thousands, the probability is close enough to 1.\
That is the key factor for this problem.

Also on how to calculate the probability. I had the traditional thinking that for each case, start with 1/4 prob and multiply to the next cases.\
In reality as the example has, we can treat each case having prob of 1 and multiple 1/4 to their sum.\
By recursive calls, probabilities from last iteration is automatically rescaled.\
In the end, scale and sum is the same as sum and scale. Very good lesson!
