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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        if(obstacleGrid.empty())
        {
            return 0;
        }

        if(obstacleGrid[0].empty())
        {
            return 0;
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        dp[0][0] = obstacleGrid[0][0] ? 0 : 1;

        for(int i = 1; i < n; ++i)
        {
            dp[0][i] = (obstacleGrid[0][i] || dp[0][i -1] == 0) ? 0 : 1;
        }

        for(int i = 1; i < m; ++i)
        {
             dp[i][0] = (obstacleGrid[i][0] || dp[i - 1][0] == 0) ? 0 : 1;
        }

        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                dp[i][j] = obstacleGrid[i][j] ? 0 : (dp[i - 1][j] + dp[i][j - 1]);
            }
        }

        return dp[m - 1][n -1];
    }
};

int main()
{
    Solution sol;
    std::cout<<sol.uniquePaths(4, 7)<<std::endl;
    return 0;
}
