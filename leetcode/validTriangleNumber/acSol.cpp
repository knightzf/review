#include "header.h"

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] == 0) continue;
            for(int j = i + 1; j < n; ++j)
            {
                auto iter = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
                res += distance(nums.begin() + j + 1, iter);
            }
        }
        return res;
    }
};

int main() {
    //Solution s;
}
