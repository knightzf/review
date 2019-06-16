This is a brilliant idea that I learned.

First I also thought of xor all the numbers which will give the result of a ^ b where a, b are the numbers we want.

And I got stuck of how to get a and b.

Then I started to think of fancy bit operations like in the Single Number II question which also failed.

The idea here is much simpler

After we know a ^ b, we can find a bit that is 1, meaning a and b are different in this bit.

For all the other numbers, they are either 1 or 0 in this number and they all appear twice.

It's then very easy to use a bit map to group all the numbers and xor each group which yield a and b.

Also an important lesson learned:

& has lower precedence than ==

Basically

if( a & b == 1) means

if( a & (b == 1))

Very tricky! Never thought of one day I needed to know details like this!

6/19\
Very tricky, the key is how to devide the existing numbers into two groups\
where numbers that appear twice will be in the same group.
