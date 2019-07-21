#include "header.h"

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m{{0, -1}};
        for(int i = 0, t = 0; i < n; ++i) {
            t += nums[i];
            if(k) t %= k;
            auto iter = m.find(t);
            if(iter != m.end() && i - iter->second > 1) return true;
            if(iter == m.end()) m[t] = i;
        }
        return false;
    }
};

int main()
{
    Solution s;
}