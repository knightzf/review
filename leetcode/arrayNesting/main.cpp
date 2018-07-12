#include "header.h"

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> steps(n, -1);
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            if(steps[i] == -1)
            {
                int t = i;
                vector<int> v;
                while(true)
                {
                    v.emplace_back(nums[t]);
                    if(nums[t] == i) break;
                    t = nums[t];
                }

                for(int j : v)
                {
                    steps[j] = v.size();
                }
                res = max(res, (int)v.size());
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
