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
#include <memory>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        if(n == 0)
        {
            return 0;
        }
        else if(n == 1)
        {
            return cost[0];
        }
        else if(n == 2)
        {
            return std::min(cost[0], cost[1]);
        }

        std::vector<int> dp(n + 1, 0);
        dp[0] = cost[0];

        for(int i = 1; i < n + 1; ++i)
        {
            dp[i] = std::min(dp[i - 1], i >= 2 ? dp[i - 2] : INT_MAX) + (i == n ? 0 : cost[i]);
        }

        std::vector<int> dp2(n + 1, 0);
        dp2[0] = INT_MAX;
        dp2[1] = cost[1];

        for(int i = 2; i < n + 1; ++i)
        {
            dp2[i] = std::min(dp2[i - 1], dp2[i - 2]) + (i == n ? 0 : cost[i]);
        }

        return std::min(dp[n], dp2[n]);
    }
};

int main()
{
    Solution s;
    std::vector<int> a{10, 15, 20};
    std::vector<int> b{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    std::cout<<s.minCostClimbingStairs(a)<<std::endl;
    std::cout<<s.minCostClimbingStairs(b)<<std::endl;
}
