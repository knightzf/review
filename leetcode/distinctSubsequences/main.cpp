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
    int numDistinct(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        if(m == 0 || n == 0)
        {
            return 0;
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j <= i && j < n; ++j)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = s[i] == t[j];
                }
                else if(i == 0)
                {
                    dp[i][j] = dp[i][j - 1] + (s[i] == t[j] ? 1 : 0);
                }
                else if(j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + (s[i] == t[j] ? 1 : 0);
                }
                else
                {
                    if(i == j)
                    {
                        //std::cout<<i<<" "<<j<<std::endl;
                        dp[i][j] = s[i] == t[j] ? dp[i - 1][j - 1] : 0;
                    }
                    else
                    {
                        dp[i][j] = s[i] == t[j] ? (dp[i - 1][j] + dp[i - 1][j - 1]) :
                            dp[i - 1][j];
                    }
                }
            }
        }

        /*for(const auto& i : dp)
        {
            for(auto j : i)
            {
                std::cout<<j<<" ";
            }
            std::cout<<std::endl;
        }*/

        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution s;
    //s.numDistinct("rabbbit", "rabbit");
    s.numDistinct("", "a");
}
