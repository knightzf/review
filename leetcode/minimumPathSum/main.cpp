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
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();

        if(m == 0)
        {
            return 0;
        }

        int n = grid[0].size();

        if(n == 0)
        {
            return 0;
        }

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        dp[0][0] = grid[0][0];

        for(int i = 1; i < n; ++i)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for(int i = 1; i < m; ++i)
        {
            dp[i][0] = dp[i -1][0] + grid[i][0];
        }

        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m -1][n - 1];
    }
};

int main()
{
    Solution sol;
    return 0;
}
