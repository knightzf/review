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
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        if(n == 0)
        {
            return 0;
        }

        int K = 2;
        vector<vector<int>> dp(K + 1, vector<int>(n, 0));

        int maxProfit = 0;

        for(int i = 1; i < K + 1; ++i)
        {
            int tempMax = dp[i - 1][0] - prices[0];
            for(int j = 1; j < n; ++j)
            {
                tempMax = std::max(tempMax, dp[i - 1][j] - prices[j]);
                dp[i][j] = std::max(dp[i][j - 1], prices[i] + tempMax);
                maxProfit = std::max(maxProfit, dp[i][j]);
            }
        }

        return maxProfit;
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 2, 4, 3, 2, 5, 7};
    s.maxProfit(a);
}
