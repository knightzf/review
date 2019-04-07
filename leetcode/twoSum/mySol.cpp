#include "header.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, unordered_set<int>> m;
        size_t n = nums.size();
        for(size_t i = 0; i < n; ++i)
        {
            m[nums[i]].insert(i);
        }

        for(size_t i = 0; i < n; ++i)
        {
            auto iter = m.find(target - nums[i]);
            if(iter != m.end())
            {
                for(auto j : iter->second)
                {
                    if(j != i)
                    {
                        return vector<int>{int(i), int(j)};
                    }
                }
            }
        }
        return {-1, -1};
    }
};

int main()
{
    Solution s;
}