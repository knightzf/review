#include "header.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for(int j = 1; j < n + 1; ++j)
        {
            if(p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 1] ? true : ((j > 1 && dp[0][j - 2]) ? true : false);
            }
        }

        for(int i = 1; i < m + 1; ++i)
        {
            for(int j = 1; j < n + 1; ++j)
            {
                switch(p[j - 1])
                {
                case '.':
                    dp[i][j] = dp[i - 1][j - 1];
                    break;
                case '*':
                    {
                        if(dp[i][j - 1])
                            dp[i][j] = true;
                        if(i > 1 && j > 1 && dp[i - 1][j - 1] && s[i - 1] == s[i - 2])
                            dp[i][j] = true;
                        //if(i > 1 && j > 1 /*&& !dp[i - 1][j - 1]*/ && dp[i - 2][j] /*&& p[j - 2] == '.'*/)
                        //std::cout<<i<<" "<<j<<" "<<dp[i][j - 2]<<std::endl;
                        if((i > 1 && dp[i - 2][j] && p[j - 2] == '.') || (j > 1 && dp[i][j - 2]))
                            dp[i][j] = true;
                        break;
                    }
                default:
                    dp[i][j] = s[i - 1] == p[j - 1] ? dp[i - 1][j - 1] : false;
                    break;
                }
            }
        }

        /*for(int i = 0; i < m + 1; ++i)
        {
            for(int j = 0; j < n + 1; ++j)
            {
                std::cout<<dp[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        //*/

        return dp[m][n];
    }
};

int main()
{
    Solution s;
    std::cout<<s.isMatch("aa", "a")<<std::endl;
    std::cout<<s.isMatch("aa", "aa")<<std::endl;
    std::cout<<s.isMatch("aaa", "aa")<<std::endl;
    std::cout<<s.isMatch("aa", "a*")<<std::endl;
    std::cout<<s.isMatch("aa", ".*")<<std::endl;
    std::cout<<s.isMatch("ab", ".*")<<std::endl;
    std::cout<<s.isMatch("aab", "c*a*b")<<std::endl;
    std::cout<<s.isMatch("aaa", "ab*ac*a")<<std::endl;
    std::cout<<s.isMatch("aaa", "ab*a*c*a")<<std::endl;
    //*/
}
