#include "header.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> t;
        function<void(int, int)> dfs = [&](int idx, int remain)
        {
            if(remain == 0) {
                res.emplace_back(t);
                return;
            }

            if(idx >= candidates.size()) return;

            if(candidates[idx] <= remain) {
                t.emplace_back(candidates[idx]);
                dfs(idx, remain - candidates[idx]);
                t.pop_back();                
                dfs(idx + 1, remain);   
            }
        };
        
        dfs(0, target);
        return res;
    }
};

int main()
{
    Solution s;
}