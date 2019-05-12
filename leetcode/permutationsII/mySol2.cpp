#include "header.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> m;        
        vector<vector<int>> res;
        int n = nums.size(); vector<int> v;
        function<void(int)> dfs = [&](int idx)
        {
            if(idx == n) {
                res.emplace_back(nums);
                return;
            }

            if(m.count(v)) return;
            m.insert(v);

            for(int i = idx; i < n; ++i)
            {                
                swap(nums[idx], nums[i]);
                v.emplace_back(nums[idx]);
                dfs(idx + 1);
                v.pop_back();
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