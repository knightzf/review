#include "header.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < n - 3; ++i)
        {
            if(i == 0 || nums[i] != nums[i - 1])
            {
                for(int j = i + 1; j < n - 2; ++j)
                {
                    if(j == i + 1 || nums[j] != nums[j - 1])
                    {
                        int k = j + 1;
                        int l = n - 1;
                        while(k < l)
                        {
                            int sum = nums[i] + nums[j] + nums[k] + nums[l];
                            if(sum > target) --l;
                            else if(sum < target) ++k;
                            else {
                                if(l == n - 1 || nums[l] != nums[l + 1]) {
                                    res.emplace_back(vector<int>{
                                        nums[i], nums[j], nums[k], nums[l]});
                                }
                                ++k;
                                --l;
                            }
                        }
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