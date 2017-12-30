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
