#include "header.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        function<int(int)> dfs = [&](int i) {
            if(!dp.count(i)) {
                int res = 0;
                for(int num : nums) {
                    if(i >= num) res += dfs(i - num);
                }
                dp[i] = res;
            }
            return dp[i];
        };
        return dfs(target);
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 2, 3};
    cout<<s.combinationSum4(a, 4)<<endl;
}