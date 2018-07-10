This problem has incredibly low acceptance rate < 10% as of now.\
It was also 3rd question of a contest.

When I did this during contest, two things I noticed:\
1. There isn't a magic way to find out whether a number is prime\
2. There isn't a magic way to find out whether a number is palindrome

Based on the two facts, I did a simple incremental search which of course timed out.

I was inspired by one of the posts althought I didn't actually looked at the code.\
However I grasped the key aspect, you need to cut the number in half.\
Instead of looking at each time to see if it's prime, we can construct prime number from half of the number given.\
There's a few corner cases/tricks in actually implementing the code but the key is divide into 2 parts.\
The complexity recuded from 10^8 to 10^4.\
I am very happy that I figured out the solution, although not entirely by myself.
