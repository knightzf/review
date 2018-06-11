#include "header.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i)
            m[nums[i]] = i;

        vector<int> res;
        for(int i = 0; i < findNums.size(); ++i)
        {
            int idx = m[findNums[i]];
            int t = -1;
            for(int j = idx + 1; j < n; ++j)
            {
                if(nums[j] > findNums[i])
                {
                    t = nums[j];
                    break;
                }
            }
            res.push_back(t);
        }
        return res;
    }
};

int main()
{
    Solution s;
}
