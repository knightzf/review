My first thought of the problem: WTF?

But looking at discussion, it's a brilliant solution.

The idea is in the result vec.

Firt shift the multiplication so that

res[i] = res[i - 1] * nums[i - 1] with initial value res[0] = 1

After this

res[1] = nums[0]

res[2] = nums[0] * nums[1]

res[3] = nums[0] * nums[1] * nums[2]


Only res[n - 1] has everything it needs, res[n - 2] misses nums[n - 1] and res[n - 3] misses nums[n - 1], nums[n - 2]

So we basically do the same thing again. This time use a temp value to hold product of nums[n - 1] * nums[n - 2] and etc

Really great thoughts
