This is pretty interesting question.

When looking by eye, you first choose the number with largest first digit, but if there are multiple ones, it becomes tricky which one to choose, i.e. order the numbers with same first digit given they might have different length.

I thought for a while and think perhaps I should make them equal length, question now is how to fill the vacancies.

For 3 and 34, we should do 34 3 instead of 3 34

So I first thought of filling remaining with first digit.

Then found this counter case 121 and 12

Correct order should be 12 121 instead of 121 12

Then I thought, ok maybe fill with last digit

Found another counter case of 84 and 847

Correct order should be 84 847 instead of 847 84

Finally i thought, maybe I should compare last digit with first digit and decide which one to use to fill the numbers.

The other tricky part is to remove 0s from left.

5/19\
I encountere exact same issue this time.\
Same thinking process and tried same approaches.\
In the end, I realized instead of trying to fill the remaining characters by\
choosing some value, what we are doing is to compare to strings and the key\
of comparison is which one is larger a + b or b + a, then this is the exact\
compare function we need.\
Glad I made a little improvement this time.
