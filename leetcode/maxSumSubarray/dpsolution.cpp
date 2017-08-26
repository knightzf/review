#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        std::vector<int> dp;
        dp.reserve(nums.size());

        int result = nums[0];
        dp.push_back(nums[0]);

        for(size_t i = 1, sz = nums.size(); i < sz; ++i)
        {
            int dpI = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
            if(dpI > result)
            {
                result = dpI;
            }

            dp.push_back(dpI);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{3, -1, 4};
    std::cout<<sol.maxSubArray(a)<<std::endl;
    return 0;
}
