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
    bool canJump(vector<int>& nums)
    {
        if(nums.empty())
        {
            return false;
        }

        int target = nums.size() - 1;

        int maxIdx = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(maxIdx >= target)
            {
                return true;
            }

            if(maxIdx >= i)
            {
                int maxIdxFromI = i + nums[i];
                maxIdx = maxIdxFromI > maxIdx ? maxIdxFromI : maxIdx;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;

    std::vector<int> a{2, 3, 1, 1, 4};
    std::vector<int> b{3, 2, 1, 0, 4};

    std::cout<<sol.canJump(a)<<std::endl;
    std::cout<<sol.canJump(b)<<std::endl;

    return 0;
}
