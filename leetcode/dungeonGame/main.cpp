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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = 1;

        for(int i = m - 2; i >=0; --i)
        {
            dp[i][n - 1] = dungeon[i + 1][n - 1] >= dp[i + 1][n - 1] ? 1 : dp[i + 1][n - 1] - dungeon[i + 1][n - 1];
        }

        for(int i = n - 2; i >=0; --i)
        {
            dp[m - 1][i] = dungeon[m - 1][i + 1] >= dp[m - 1][i + 1] ? 1 : dp[m - 1][i + 1] - dungeon[m - 1][i + 1];
        }

        for(int i = m - 2; i >= 0; --i)
        {
            for(int j = n - 2; j >= 0; --j)
            {
                int a = dungeon[i + 1][j] >= dp[i + 1][j] ? 1 : dp[i + 1][j] - dungeon[i + 1][j];
                int b = dungeon[i][j + 1] >= dp[i][j + 1] ? 1 : dp[i][j + 1] - dungeon[i][j + 1];
                dp[i][j] = std::min(a, b);
            }
        }

        return dungeon[0][0] >= dp[0][0] ? 1 : dp[0][0] - dungeon[0][0];
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>> a{{-3, 5}};
        std::cout<<s.calculateMinimumHP(a)<<std::endl;;
    }
    {
        vector<vector<int>> a{{0, -3}};
        std::cout<<s.calculateMinimumHP(a)<<std::endl;;
    }

}
