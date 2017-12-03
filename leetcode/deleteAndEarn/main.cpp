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
#include <unordered_map>
#include <unordered_set>
#include <cstring>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        if(nums.empty())
            return 0;

        int count[10001];
        memset(count, 0, 10001);

        int min = 20000;
        int max = -1;
        for(int i : nums)
        {
            min = i < min ? i : min;
            max = i > max ? i : max;
            ++count[i];
        }
        //std::cout<<min<<" "<<max<<std::endl;
        //std::cout<<count[1]<<std::endl;

        std::vector<int> dp(max + 1, 0);
        for(int i = min; i <= max; ++i)
        {
            dp[i] = std::max(dp[i - 1], i * count[i] + (i - 2 >= 0 ? dp[i - 2] : 0));
            //std::cout<<dp[i]<<std::endl;
        }

        return dp[max];
    }
};

int main()
{
    Solution s;
    vector<int> nums{1,8,5,9,6,9,4,1,7,3,3,6,3,3,8,2,6,3,2,2,1,2,9,8,7,1,1,10,6,7,3,9,6,10,5,4,10,1,6,7,4,7,4,1,9,5,1,5,7,5};
    std::cout<<s.deleteAndEarn(nums)<<std::endl;
}
