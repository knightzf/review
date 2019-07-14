#include "header.h"

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> t;
        for(int i = 0, n = nums.size(), currMin = INT_MAX; i < n; ++i) {
            if(nums[i] > currMin) t.emplace_back(i);
            currMin = min(currMin, nums[i]);
        }
        if(t.empty()) return false;
        for(int i = 0, n = t.size(), currMin = INT_MAX; i < n; ++i) {
            if(nums[t[i]] > currMin) return true;
            currMin = min(currMin, nums[t[i]]);
        }
        return false;
    }
};

int main()
{
    Solution s;
}