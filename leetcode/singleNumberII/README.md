Again trivia problem if not requesting of not using extra space.

Similar to Single Number problem, the goal is to find a way so that it'll eliminate numbers that appears 3 times.

Bit operations is the same for a single bit or a 4 byte number, it has 4 states.

0 -> 1 -> 2 -> 0

Essentially it goes back to 0 when seeing this number at the 3rd time.

Using a binany format

00 -> 10 -> 01 -> 00

It means when seeing the number the first time, the left bit becomes 1

              seeing the number the second time, the left bit becomes 0 and right becomes 1

              seeing the number the second time, the left bit becomes 0 and right becomes 0


In order to achieve this

Use two numbers to denote left and right bit, namely ones and twos

    ones = (ones ^ nums[i]) & ~twos;

    twos = (twos ^ nums[i]) & ~ones;


A simple example

The array has 1 1 1 2

    ones   twos
1   0001   0000
1   0000   0001
1   0000   0000
2   0010   0000

What does it mean?

XOR sets the number against 0, the AND operator resets the number if the other number is non-zero

5/19\
Took me a few days to undertand this problem again.\
First idea is we can count the numbers of 1's at each bit and mod by 3 which gives us the bits that are 1.\
The bit pattern is the number look for.
```C++
int singleNumber(int A[], int n) {
    int count[32] = {0};
    int result = 0;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < n; j++) {
            if ((A[j] >> i) & 1) {
                count[i]++;
            }
        }
        result |= ((count[i] % 3) << i);
    }
    return result;
}
```
A very good explanation is here 
https://blog.csdn.net/wlwh90/article/details/89712795

Suppose we want to find how many 1's in a list of bits, how do we count it?\
Surely we can use an int, what about thinking of how the individual bits of the int changes?\
When there is 1 bit, the count is [0 1] as binary.\
When it comes another 1 bit, the count is now [1 0]. When does the most significant bit becomes 1? \
It's when the least significate bit is 1 and the incoming bit is also 1.\
Basically for each bit, it only becomes one when all bits on its right are 1 and the incoming bit is 1.

Next step, we need to set the count to 0 when we see 3 bits of 1.\
The count is now [1 1], in order to make it [0 0], we can do count & mask.\
How to create this mask? it's not obvious in this example.\
Suppose we need to set the count to 0 when it's 5 ([1 0 1]).\
For each bit we need 1 & mask = 0, 0 & mask = 0 and 1 & mask = 0.\
The mask is 0 but it can only be 0 when the count is 5.\
So the mask can be calcualted as ~(1 & ~0 & 1).\
Let's give the count bits names of x1, x2, x3, x4... xm.\
And the critical k in binary as k1, k2, ... km
The mask is ~(y1 & y2 & y3 ... $ ym) where yi = xi if ki == 1, otherwise yi = ~xi

Then we can extend the algo to a list of 32 bit numbers.\
For each bit, we can do same thing or we can treat 32 bit number the same way as a single bit.\
This is because bit operations are independent of each other.\
In the end, the result we need is xi where ki == 1. Why? Because other numbers should be 0 now.