#include "header.h"

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n - k + 1, 0);
        for(int i = 0; i < k; ++i)
            sum[0] += nums[i];
        for(int i = 1; i < n -k + 1; ++i)
        {
            sum[i] = sum[i - 1] - nums[i - 1] + nums[i + k - 1];
        }

        /*for(int i : sum)
            std::cout<<i<<" ";
        std::cout<<std::endl;
        //*/

        //find first max left start idx as of current start idx
        vector<int> leftStartIdx(n, -1);
        for(int i = 0, localMax = sum[0]; i <= n - 3 * k; ++i)
        {
            if(i > 0 && localMax >= sum[i])
            {
                leftStartIdx[i] = leftStartIdx[i - 1];
            }
            else
            {
                leftStartIdx[i] = i;
                localMax = sum[i];
            }

        }
        /*for(int i : leftStartIdx)
            std::cout<<i<<" ";
        std::cout<<std::endl;
        //*/

        vector<int> rightStartIdx(n, -1);
        for(int i = n - k, localMax = sum[i]; i >= 2 * k; --i)
        {
            if(i < n - k && sum[i] < localMax)
            {
                rightStartIdx[i] = rightStartIdx[i + 1];
            }
            else
            {
                rightStartIdx[i] = i;
                localMax = sum[i];
            }
        }
        /*for(int i : rightStartIdx)
            std::cout<<i<<" ";
        std::cout<<std::endl;
        //*/

        vector<int> res;
        int totalMax = 0;
        for(int i = k; i <= n - 2 * k; ++i)
        {
            int t = sum[leftStartIdx[i - k]] + sum[i] + sum[rightStartIdx[i + k]];
            //std::cout<<t<<" "<<leftStartIdx[i - k]<<" "<<i<<" "<<rightStartIdx[i + k]<<std::endl;
            if(t > totalMax)
            {
                totalMax = t;
                res = {leftStartIdx[i - k], i, rightStartIdx[i + k]};
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 2, 1, 2, 6, 7, 5, 1};
    s.maxSumOfThreeSubarrays(a, 2);
}
