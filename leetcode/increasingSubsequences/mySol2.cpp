#include "header.h"

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> v;
        function<void(int)> dfs = [&](int idx) {
            if(v.size() >1) res.emplace_back(v);
            unordered_set<int> hash;
            for(int i = idx; i < n; ++i) {
                if((v.empty() || nums[i] >= v.back()) && !hash.count(nums[i])) {
                    v.push_back(nums[i]);
                    dfs(i + 1);
                    v.pop_back();
                    hash.insert(nums[i]);
                }
            }
        };
        dfs(0);
        return res;
    }
};

int main()
{
    //Solution s;
}