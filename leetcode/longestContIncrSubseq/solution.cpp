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
    int findLengthOfLCIS(vector<int>& nums)
    {
        int max = 0;
        int result = 0;
        for(size_t i = 0, sz = nums.size(); i < sz; ++i)
        {
            if(i == 0)
            {
                ++result;
            }
            else
            {
                if(nums[i] > nums[i - 1])
                {
                    ++result;
                }
                else
                {
                    max = result > max ? result : max;
                    result = 1;
                }
            }
        }

        max = result > max ? result : max;

        return max;
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{2, 2, 2, 2, 2};
    std::cout<<sol.findLengthOfLCIS(a)<<std::endl;
    return 0;
}
