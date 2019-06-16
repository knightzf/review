#include "header.h"

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0, n = nums.size(); i < n; ++i) {
            for(int j = i + 1, k = n - 1; j < n && k > j; ++j) {
                int t = nums[i] + nums[j];
                while(k > j && t + nums[k] >= target) --k;
                res += k - j;
            }
        }
        return res;
    }
};

int main()
{
    //Solution s;
}