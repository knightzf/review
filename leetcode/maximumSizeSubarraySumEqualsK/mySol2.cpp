#include "header.h"

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> m{{0, -1}};
        int res = 0;
        for(int i = 0, n = nums.size(), sum = 0; i < n; ++i) {
            sum += nums[i];
            if(!m.count(sum)) m[sum] = i;
            if(m.count(sum - k)) res = max(res, i - m[sum - k]);
        }
        return res;
    }
};

int main()
{
    Solution s;
}