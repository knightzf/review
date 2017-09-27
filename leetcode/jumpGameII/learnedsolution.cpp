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
#include <bitset>
#include <stack>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums)
    {
        if(nums.size() < 2)
        {
            return 0;
        }

        int n = nums.size();

        int level = 0;
        int maxReachableIdx = 0;
        int startIdx = -1;

        while(true)
        {
            //std::cout<<maxReachableIdx<<std::endl;
            ++level;

            int maxReachableIdxForThisLevel = 0;
            bool found = false;

            for(int i = startIdx + 1; i <= maxReachableIdx; ++i)
            {
                maxReachableIdxForThisLevel = std::max(maxReachableIdxForThisLevel, i + nums[i]);
                if(maxReachableIdxForThisLevel >= n - 1)
                {
                    found = true;
                    break;
                }
            }

            if(found)
            {
                break;
            }
            else
            {
                startIdx = maxReachableIdx;
                maxReachableIdx = maxReachableIdxForThisLevel;
            }
        }

        return level;
    }
};

int main()
{
    Solution sol;
    //std::vector<int> a{2, 3, 1, 1, 4};
    std::vector<int> a{1, 2};
    std::cout<<sol.jump(a)<<std::endl;
    return 0;
}
