#include "header.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), res = n + 1;
        for(int i = 0, j = 0, sum = 0; i < n; ++i) {
            sum += nums[i];
            while(j <= i && sum >= s) {
                res = min(res, i - j + 1);
                sum -= nums[j];
                ++j;
            }
        }
        return res > n ? 0 : res;
    }
};

int main()
{
    //Solution s;
}