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
    struct Pt
    {
        Pt(int x_, int y_) : x(x_), y(y_)
        {
        }

        bool operator<(const Pt& rhs) const
        {
            if(x < rhs.x)
            {
                return true;
            }
            else if(x == rhs.x)
            {
                if(y < rhs.y)
                {
                    return true;
                }
            }

            return false;
        }

        bool operator==(const Pt& rhs) const
        {
            return x == rhs.x && y == rhs.y;
        }

        int x;
        int y;
    };

    int uniquePaths(int m, int n)
    {
        if(m == 0 || n == 0)
        {
            return 0;
        }

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        for(int i = 0; i < n; ++i)
        {
            dp[0][i] = 1;
        }

        for(int i = 1; i < m; ++i)
        {
            dp[i][0] = 1;
        }

        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
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
