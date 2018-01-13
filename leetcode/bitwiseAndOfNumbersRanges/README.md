This question took me quite some time.

At first, it seems to be a dummy one, just AND all number but that's obviously too slow.

Then I looked at the binary format and thought perhaps I can first find the number of digits in binary, then check if there's 0 in each bit.

After some struggle I found if there's number with more digits than the start number, the result has to be 0.

For example m = 110 and n = 11000

From m to n, there must be a number 1000 that will make the result 0.

Then it becomes clearer, also need check if m == 0, which is hard to count the bits.

The genius use of checking if number is power of 2 is used again.

if((n & (n - 1)) == 0)

Note that == has higher precedence than &
