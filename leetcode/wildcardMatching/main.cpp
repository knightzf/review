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
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();

        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, 0));

        dp[0][0] = true;

        for(int i = 1; i < n + 1; ++i)
        {
            if(p[i - 1] == '*')
            {
                dp[0][i] = dp[0][i - 1];
            }
        }

        for(int i = 1; i < m + 1; ++i)
        {
            for(int j = 1; j < n + 1; ++j)
            {
                if(dp[i][j - 1] && p[j - 1] == '*')
                {
                    dp[i][j] = true;
                }

                if(dp[i - 1][j] && p[j - 1] == '*')
                {
                    dp[i][j] = true;
                }

                if(dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?' || p[j - 1] == '*'))
                {
                    dp[i][j] = true;
                }
            }
        }

        return dp[m][n];
    }
};
int main()
{
    Solution sol;
    std::cout<<sol.isMatch("aa","a")<<std::endl;
    std::cout<<sol.isMatch("aa","aa")<<std::endl;
    std::cout<<sol.isMatch("aaa","aa")<<std::endl;
    std::cout<<sol.isMatch("aa", "*")<<std::endl;
    std::cout<<sol.isMatch("aa", "a*")<<std::endl;
    std::cout<<sol.isMatch("ab", "?*")<<std::endl;
    std::cout<<sol.isMatch("aab", "c*a*b")<<std::endl;

    return 0;
}
