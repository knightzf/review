Again learned a lot from this question.

First tried normal dfs, which timesout for a large input.\
Then I thought about dp however in the wrong direction. \
Then I found my original thinking direction was right, only got into wrong details that makes the problem harder.\
My dp solution requires using an unordered map, which slows down the speed.

The learned solution is much faster in that it initialize dp values to -1 and use 0 to denote numbers can't be reached.\
It's like a dp plus dfs solution which is really smart.\
The dp[0] is set to 1 which is necessary because for any target number can be reached, 0 is the result of a final subtraction.\
Because the problem has condition of all positive numbers so using 0 is not a problem.

Another even simpler dp solution\

```C++
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        sort (nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i < num) break;
                dp[i] += dp[i - num];
            }
        }
        return dp.back();
    }
};
```

3/2019\
Again I thought the dp in a wrong direction in that I essentially find out number of unique combinations.\
However for this problem it allows things like [1, 2] and [2, 1] being different.\
I even thought about using a 3d dp which seems to be overreaching.\
Then I realized it's a simple 1d dp where for each new target number, we find subproblem results by subtracting each number.

Tried to use the dp solution below and it errors out due to integer overflow. I guess the acceppted solution is better.
```C++
class Solution {
    public:
        int combinationSum4(vector<int>& nums, int target) {
            int n = nums.size();
            vector<int> dp(target + 1, 0);
            dp[0] = 1;
            for(int i = 1; i < target + 1; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if(i >= nums[j])
                    {
                        dp[i] += dp[i - nums[j]];
                    }
                }
            }
            return dp[target];
        }
};

```
