#include "header.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; ++i) m[nums[i]] = i;
        vector<vector<int>> res;
        for(int i = 0; i < n; ++i)
        {
            if(i == 0 || nums[i] != nums[i - 1])
            {
                for(int j = i + 1; j < n; ++j)
                {
                    if(j == i + 1 || nums[j] != nums[j - 1])
                    {
                        int sum = nums[i] + nums[j];
                        if(m.count(-sum) && m[-sum] > j)
                        {
                            res.emplace_back(vector<int>{nums[i], nums[j], -sum});
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