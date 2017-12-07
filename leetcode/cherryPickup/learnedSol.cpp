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
    int cherryPickup(vector<vector<int>>& grid)
    {
        int n = grid.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        dp[0][0] = grid[0][0];

        int totalSteps = 2 * (n - 1);

        for(int k = 1; k <= totalSteps; ++k)
        {
            vector<vector<int>> tempDp(n, vector<int>(n, -1));

            for(int i = 0; i <= k && i < n; ++i)
            {
                if(k - i >= n)
                {
                    continue;
                }

                for(int j = 0; j <= k && j < n; ++j)
                {
                    if(k - j >= n)
                    {
                        continue;
                    }

                    if (grid[i][k - i] < 0 || grid[j][k - j] < 0) { // keep away from thorns
                        continue;
                    }

                    int cherries = dp[i][j];

                    if(i > 0)
                    {
                        cherries = std::max(cherries, dp[i - 1][j]);
                    }

                    if(j > 0)
                    {
                        cherries = std::max(cherries, dp[i][j - 1]);
                    }

                    if(i > 0 && j > 0)
                    {
                        cherries = std::max(cherries, dp[i - 1][j - 1]);
                    }

                    if (cherries < 0)
                    {
                        continue;
                    }

                    tempDp[i][j] = cherries + grid[i][k - i] + (i == j ? 0 : grid[j][k - j]);
                }
            }

            dp = std::move(tempDp);
        }

        return std::max(dp[n - 1][n - 1], 0);
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> a {
        {0, 1, -1},
        {1, 0, -1},
        {1, 1, 1}
    };
    s.cherryPickup(a);
}
