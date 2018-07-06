#include "header.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            sum += nums[i];
            if(m.count(sum - k))
            {
                res += m[sum - k];
            }
            ++m[sum];
        }
        return res;
    }
};

int main()
{
    Solution s;
}
