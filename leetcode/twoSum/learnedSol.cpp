#include "header.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        size_t n = nums.size();
        for(size_t i = 0; i < n; ++i)
        {
            auto iter = m.find(target - nums[i]);
            if(iter != m.end())
            {
                return vector<int>{int(i), iter->second};
            }
            else
            {
                m[nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};

int main()
{
    Solution s;
}