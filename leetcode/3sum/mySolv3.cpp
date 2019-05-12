#include "header.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < n - 2; ++i)
        {
            if(i == 0 || nums[i] != nums[i - 1])
            {
                int j = i + 1;
                int k = n - 1;
                while(j < k)
                {
                    if(nums[i] + nums[j] + nums[k] > 0) --k;
                    else if(nums[i] + nums[j] + nums[k] < 0) ++j;
                    else {
                        if(k == n - 1 || nums[k] != nums[k + 1]) {
                            res.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                        }
                        ++j;
                        --k;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}