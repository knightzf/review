My solution is try to find all combinations of numbers and operators and then eval each of them.

The problem with it, is too many copies which creates a lot of string vectors which times out.

The learned solution is essentially the same idea, the better part is it only constructs temp string expressions.

Besides, it calculates the result at the same time and uses a temp value to store last addition to calc result.

Lessons learned.
