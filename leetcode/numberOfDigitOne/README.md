I knew this is not going to be counting all the numbers from 1 to n.

But the idea is pretty neat.

It counts occurance of 1's at each position.

For example for all the numbers, 1 appears on the 100th position x times.

How to find that?

For a number like this 123426, 100th number if 4, from 1 to 426, there are 100 numbers that have 1 at this position (i.e. 100, 101...199)

So the total number of 1's at 100th position is 124 * 100 (i.e. 124 possible numbers "" to 123)

If the 100th number is 1 (123126), there's only 27 such numbers (100, 101..126), so total is 123 * 100 (""  to 122) + 27

If the 100th number is 0 (123026), there is no such number so total is 123 * 100 ("" to 122)


So the logic is

int a = n / 100; int b = n % 100; // here a = 1234, b = 26
(a + 8) / 10 * 100 + (a % 10 == 1) * (b + 1)
