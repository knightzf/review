I thought for long time but couldn't get a good solution, it feels as if you'll have to go through all length k to n\
to find the max average.

The learned solution, the key idea is we know the min max or the average, and do binary search to check if for given\
average, is it possible to find a subarray with size [k, n] that has average >= given number.

It still feels you'd have to try all possible subarray lengths, but there's a better way.\
If there's size m subarray that has average >= given average, so that\
nums[0] - avg + nums[1] - avg ... + nums[m - 1] - avg >= 0\

We first find sum of first k numbers - avg * k, if it's already >= 0, then we are good.\
Otherwise, we keep adding num[i] - avg while use another variable to keep track of nums[i - k] - avg\
use another varialbe minsum to find minimum of sum of nums[i - k] - avg.\
As long as total sum - minsum >= 0, it means there must be a size m that satisfies the avg.\
Another key is the minsum is initialized with value, because if sum of first k is already negative, we'd \
want to substract a negative number, if minsum is initialized to be a large value, we could be subtracting\
minsum > 0 which will not satify.

In my own thinking process, I also thought of possibility of looking at subproblem, for example, if we know the max\
avg for size k, we know max avg of size n*k can never exceed the previous max because n*k is constructed by n consecutive\
size k subarrays.\

But that has a problem, say if k >= n / 2, above relationship can't be used as k + 1, k + 2... n can't be constructed\
by existing sub problems.
