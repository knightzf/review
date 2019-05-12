#include "header.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        function<void(int)> dfs = [&](int idx)
        {
            if(idx == n) {
                res.emplace_back(nums);
                return;
            }

            for(int i = idx; i < n; ++i)
            {
                swap(nums[idx], nums[i]);
                dfs(idx + 1);
                swap(nums[idx], nums[i]);
            }
        };

        dfs(0);
        return res;
    }
};

int main()
{
    Solution s;
}