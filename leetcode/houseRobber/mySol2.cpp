#include "header.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> v{nums[0], nums[1], nums[0] + nums[2]};
        int res = max(nums[1], nums[0] + nums[2]);
        for(int i = 3; i < n; ++i) {
            int t = nums[i] + max(v[0], v[1]);
            res = max(res, t);
            v[0] = v[1]; v[1] = v[2], v[2] = t;
        }
        return res;
    }
};

int main()
{
    Solution s;
}