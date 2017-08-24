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

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int sum = 0;

        std::sort(nums.begin(), nums.end());

        for(size_t i = 0, sz = nums.size() - 2; i < sz; ++i)
        {
            int a = nums[i];

            size_t bIdx = i + 1;
            size_t cIdx = nums.size() - 1;

            while(bIdx != cIdx)
            {
                int total = a + nums[bIdx] + nums[cIdx];

                if(total < target)
                {
                    ++bIdx;
                }
                else if(total > target)
                {
                    --cIdx;
                }
                else
                {
                    return target;
                }

                int tempDiff = std::abs(total - target);
                if(tempDiff < diff)
                {
                    sum = total;
                    diff = tempDiff;
                }
            }
        }

        return sum;
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{-1, 2, 1, -4};
    std::cout<<sol.threeSumClosest(a, 2)<<std::endl;;
    return 0;
}
