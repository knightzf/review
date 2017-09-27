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
        if(nums.empty())
        {
            return 0;
        }

        int n = nums.size();

        std::vector<int> dp(n, -1);
        dp[0] = 0;

        //std::map<int, int> jumpIdxMap;

        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[j] >= i - j && dp[j] != -1)
                {
                    dp[i] = 1 + dp[j];
                    break;
                }
            }
        }

        /*for(auto i : dp)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;*/

        return dp[n - 1];
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{2, 3, 1, 1, 4};
    std::cout<<sol.jump(a)<<std::endl;
    return 0;
}
