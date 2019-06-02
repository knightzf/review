It is definitely a dp problem.

The issue is how to define the dp definition.

My solution is to denote dp[i] as the max value includeing nums[i].

So dp[i] is euqal to nums[i] + max(dp[i - 2], dp[i - 1] - nums[i -1])

5/19\
I did it again, clumzily.\
Checking discussion, there's a better/cleaner solution that find the dp[i] of\
the max profit at house i of the max of dp[i - 2] + nums[i] and dp[i - 1], \
basically two choices at i: either rob it or skip it.\
The code is then very clearn:
```Java
public int rob(int[] nums) {
    if (nums.length == 0) return 0;
    int prev1 = 0;
    int prev2 = 0;
    for (int num : nums) {
        int tmp = prev1;
        prev1 = Math.max(prev2 + num, prev1);
        prev2 = tmp;
    }
    return prev1;
}
```
