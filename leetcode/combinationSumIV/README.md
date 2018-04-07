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
