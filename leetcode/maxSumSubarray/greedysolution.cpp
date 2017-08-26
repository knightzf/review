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
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }

        int minSum = 0;
        int sum = 0;
        int result = nums[0];

        for(size_t i = 0, sz = nums.size(); i < sz; ++i)
        {
            sum += nums[i];

            if(sum - minSum > result) result = sum - minSum;
            if(sum < minSum) minSum = sum;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{-2, -1};
    std::cout<<sol.maxSubArray(a)<<std::endl;
    return 0;
}
