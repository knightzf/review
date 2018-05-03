Very smart bit operation and 2sum idea.

The learned solution basically start from left to right bits and check if there are two numbers so that their ith bit xor is 1.\
In order to do that, it uses a mask starts from 1000000.. to 111100000 at each iteration.\
Then similar to 2sum, instead of N^2 addition, it looks for remaining number in a hashtable.\
Here it's doing the same thing, just harder to see.\
It uses property of xor in that\
a ^ b = c -> a ^ c = b and b ^ c = a

Feel my IQ being challenged everyday.
