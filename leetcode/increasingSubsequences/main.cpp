#include "header.h"

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;

        int n = nums.size();
        vector<vector<vector<int>>> temp(n);
        set<pair<int, int>> s;

        for(int i = 0; i < n; ++i)
        {
            if(temp[i].empty())
                impl(nums, temp, s, i, n);
        }

        unordered_set<int> visited;
        for(int i = 0; i < n; ++i)
        {
            if(visited.count(nums[i]) == 0)
            {
                visited.insert(nums[i]);
                if(temp[i].size() > 1)
                {
                    auto iter = temp[i].begin();
                    ++iter;
                    res.insert(res.end(), iter, temp[i].end());
                }
            }
        }

        return res;
    }

    void impl(vector<int>& nums, vector<vector<vector<int>>>& temp, set<pair<int, int>>& s, int idx, int n)
    {
        temp[idx].push_back({nums[idx]});
        for(int j = idx + 1; j < n; ++j)
        {
            if(nums[j] >= nums[idx] && s.count(make_pair(idx, nums[j])) == 0)
            {
                s.emplace(idx, nums[j]);
                if(temp[j].empty())
                {
                    impl(nums, temp, s, j, n);
                }

                for(const auto& v : temp[j])
                {
                    auto t = v;
                    t.insert(t.begin(), nums[idx]);
                    temp[idx].emplace_back(t);
                }
            }
        }
    }
};

int main()
{
    Solution s;
    //vector<int> a{1, 1, 1, 1, 1};
    //vector<int> a{1, 2, 3, 1, 1, 1};
    vector<int> a{4, 3, 2, 1};
    s.findSubsequences(a);
}
