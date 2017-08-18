The problem is more math than programming.

I tried to count the numbers that are removed by checking 1 digit numbers, 2 digit numbers and etc and there is a formula that I can draw. However it is still very tricky to find the nth number after removing all the numbers containing 9.

Looking at numbers remaning, it becomes obvious that they are 9-based numbers, which is not a normal thing people would think of. Basically number after 8 is 10, number after 18 is 20, number after 88 is 100.

Then it's just a conversion of decimal number to 9 based number.

-----------
Talked to a friend today and he remined me that taking out any number is the same as taking out number 9. It's still a 9 based system, the only difference is the 9 digits are different. We only need to adjust the result by replacing numbers (for example if we take out 7, then the resulting 7 is 8, 8 is 9.)

Also works if we take out any number of numbers, same idea of replacement.
